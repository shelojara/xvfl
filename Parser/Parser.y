%{
	#include <string>
	#include <vector>
	#include <memory>

    #include "../../AST/Program.hpp"
    #include "../../AST/StructAST.hpp"
    #include "../../TypeSystem/Types.hpp"

	size_t yyline = 1;

	int yydebug = 1;

	extern int yylex();

	extern Program program;

	void yyerror(const char *str)
	{
        throw std::runtime_error(std::string(str) + " at line " + std::to_string(yyline));
	}
%}

%union
{
	ParameterList * parameterList;
	ExpressionList * expressionList;

	BlockAST * block;
	FunctionAST * function;
	StructAST * structDef;
	StatementAST * statement;
	ExpressionAST * expression;
	Type * type;

	std::string * string;
	int integer;
	int token;
	float floatNumber;
}

%error-verbose

%token VAR ASSIGN END RETURN IF ELSE PRINT VOID FOR TRUE FALSE PRINT_F

%token <token> PLUS MINUS MULT DIV EQ NEQ LESS GREATER LEQ GEQ MOD
%token <integer> INTEGER
%token <floatNumber> FLOAT
%token <string> FUNCTION_NAME STRUCT_NAME IDENTIFIER STRING

%type <structDef> struct
%type <function> function
%type <parameterList> parameterList structMembers
%type <block> block
%type <type> typeName
%type <statement> statement assignment return variableDeclaration if print for
%type <expression> expression versionInv functionCall
%type <expressionList> expressionList

%left EQ NEQ
%left LESS GREATER
%left LEQ GEQ
%left PLUS MINUS
%left MULT DIV MOD

%right IDENTIFIER '['

%start program

%%

program:
	// empty
	| program function
	{
		program.addFunction($2);
	}
	| program struct
    {
        program.addStruct($2);
    }
	;

function:
	FUNCTION_NAME '(' parameterList ')' block END
	{
		$$ = new FunctionAST(*$1, *$3, std::shared_ptr<BlockAST>($5));
	}
	| FUNCTION_NAME '(' parameterList ')' ':' typeName block END
	{
		$$ = new FunctionAST(*$1, *$3, std::shared_ptr<BlockAST>($7), "", std::shared_ptr<Type>($6));
	}
	| FUNCTION_NAME '(' IDENTIFIER ';' parameterList ')' block END
	{
		$$ = new FunctionAST(*$1, *$5, std::shared_ptr<BlockAST>($7), *$3);
	}
	| FUNCTION_NAME '(' IDENTIFIER ';' parameterList ')' ':' typeName block END
	{
		$$ = new FunctionAST(*$1, *$5, std::shared_ptr<BlockAST>($9), *$3, std::shared_ptr<Type>($8));
	}
	;

parameterList:
	// empty
	{
		$$ = new ParameterList();
	}
	| parameterList ',' typeName IDENTIFIER
	{
		$1->push_back(std::make_shared<ParameterAST>(*$4, std::shared_ptr<Type>($3)));
	}
	| typeName IDENTIFIER
	{
		$$ = new ParameterList();
		$$->push_back(std::make_shared<ParameterAST>(*$2, std::shared_ptr<Type>($1)));
	}
	;

struct:
    STRUCT_NAME structMembers END
    {
        $$ = new StructAST(*$1, *$2);
    }
    ;

structMembers:
    // empty.
    {
        $$ = new std::vector<std::shared_ptr<ParameterAST>>();
    }
    | structMembers IDENTIFIER IDENTIFIER
    {
        $1->push_back(std::make_shared<ParameterAST>(*$3, std::make_shared<Type>(*$2)));
    }
    | structMembers STRUCT_NAME IDENTIFIER
    {
        $1->push_back(std::make_shared<ParameterAST>(*$3, std::make_shared<StructType>(*$2)));
    }
    ;

variableDeclaration:
	VAR IDENTIFIER ':' typeName ASSIGN expression
	{
		$$ = new VarDeclAST(*$2, std::shared_ptr<Type>($4), std::shared_ptr<ExpressionAST>($6));
	}
	| VAR IDENTIFIER ASSIGN expression
	{
		$$ = new VarDeclAST(*$2, std::shared_ptr<Type>(nullptr), std::shared_ptr<ExpressionAST>($4));
	}
	| VAR IDENTIFIER ':' typeName
	{
		$$ = new VarDeclAST(*$2, std::shared_ptr<Type>($4));
	}
	;

typeName:
	IDENTIFIER
	{
		$$ = new Type(*$1);
	}
	| IDENTIFIER '[' expression ']'
	{
		$$ = new ArrayType(*$1, std::shared_ptr<ExpressionAST>($3));
	}
	| STRUCT_NAME
	{
	    $$ = new StructType(*$1);
	}
	| IDENTIFIER '[' ']'
	{
		$$ = new ArrayType(*$1);
	}
	;

block:
	// empty
	{
		$$ = new BlockAST();
	}
	| block statement
	{
		$1->addStatement(std::shared_ptr<StatementAST>($2));
	}
	;

statement:
	assignment
	| expression
	{
		$$ = new ExpressionStatementAST(std::shared_ptr<ExpressionAST>($1));
	}
	| return
	| variableDeclaration
	| if
	| print
	| for
	;

assignment:
	IDENTIFIER ASSIGN expression
	{
		$$ = new AssignmentAST(*$1, std::shared_ptr<ExpressionAST>($3));
	}
	| IDENTIFIER '[' expression ']' ASSIGN expression
	{
		$$ = new ArrayAssignmentAST(*$1, std::shared_ptr<ExpressionAST>($3),
		        std::shared_ptr<ExpressionAST>($6));
	}
	| IDENTIFIER '.' IDENTIFIER ASSIGN expression
	{
		$$ = new StructAssignmentAST(*$1, *$3, std::shared_ptr<ExpressionAST>($5));
	}
	;

expression:
	functionCall
	| versionInv
	| STRING
	{
		$$ = new StringAST(*$1);
	}
	| IDENTIFIER '[' expression ']'
	{
		$$ = new ArrayIndexAST(*$1, std::shared_ptr<ExpressionAST>($3));
	}
	| IDENTIFIER '.' IDENTIFIER
	{
		$$ = new StructMemberAST(*$1, *$3);
	}
	| IDENTIFIER
	{
		$$ = new IdentifierAST(*$1);
	}
	| INTEGER
	{
		$$ = new IntegerAST($1);
	}
	| FLOAT
	{
		$$ = new FloatAST($1);
	}
	| expression PLUS expression
	{
		$$ = new BinaryOpAST(std::shared_ptr<ExpressionAST>($1), "+", std::shared_ptr<ExpressionAST>($3));
	}
	| expression MULT expression
	{
		$$ = new BinaryOpAST(std::shared_ptr<ExpressionAST>($1), "*", std::shared_ptr<ExpressionAST>($3));
	}
	| expression DIV expression
	{
		$$ = new BinaryOpAST(std::shared_ptr<ExpressionAST>($1), "/", std::shared_ptr<ExpressionAST>($3));
	}
	| expression MINUS expression
	{
		$$ = new BinaryOpAST(std::shared_ptr<ExpressionAST>($1), "-", std::shared_ptr<ExpressionAST>($3));
	}
	| expression EQ expression
	{
		$$ = new BinaryOpAST(std::shared_ptr<ExpressionAST>($1), "==", std::shared_ptr<ExpressionAST>($3));
	}
	| expression NEQ expression
	{
		$$ = new BinaryOpAST(std::shared_ptr<ExpressionAST>($1), "!=", std::shared_ptr<ExpressionAST>($3));
	}
	| expression LESS expression
	{
		$$ = new BinaryOpAST(std::shared_ptr<ExpressionAST>($1), "<", std::shared_ptr<ExpressionAST>($3));
	}
	| expression GREATER expression
	{
		$$ = new BinaryOpAST(std::shared_ptr<ExpressionAST>($1), ">", std::shared_ptr<ExpressionAST>($3));
	}
	| expression LEQ expression
	{
		$$ = new BinaryOpAST(std::shared_ptr<ExpressionAST>($1), "<=", std::shared_ptr<ExpressionAST>($3));
	}
	| expression GEQ expression
	{
		$$ = new BinaryOpAST(std::shared_ptr<ExpressionAST>($1), ">=", std::shared_ptr<ExpressionAST>($3));
	}
	| expression MOD expression
	{
		$$ = new BinaryOpAST(std::shared_ptr<ExpressionAST>($1), "%", std::shared_ptr<ExpressionAST>($3));
	}
	| '(' expression ')'
	{
		$$ = $2;
	}
	| '[' expressionList ']'
	{
		$$ = new ArrayAST(*$2);
	}
	| TRUE
	{
	    $$ = new BoolAST(true);
	}
	| FALSE
	{
	    $$ = new BoolAST(false);
	}
	;

functionCall:
	FUNCTION_NAME '(' expressionList ')'
	{
		$$ = new FunctionCallAST(*$1, "", *$3);
	}
	| FUNCTION_NAME '(' IDENTIFIER ';' expressionList ')'
	{
		$$ = new FunctionCallAST(*$1, *$3, *$5);
	}

versionInv:
	'@' '(' expressionList ')'
	{
		$$ = new VersionInvAST("", *$3);
	}
	| '@' '(' IDENTIFIER ';' expressionList ')'
	{
		$$ = new VersionInvAST(*$3, *$5);
	}
	;

expressionList:
	// empty
	{
		$$ = new ExpressionList();
	}
	| expressionList ',' expression
	{
		$1->push_back(std::shared_ptr<ExpressionAST>($3));
	}
	| expression
	{
		$$ = new ExpressionList();
		$$->push_back(std::shared_ptr<ExpressionAST>($1));
	}
	;

return:
	RETURN VOID
	{
		$$ = new ReturnAST();
	}
	| RETURN expression
	{
		$$ = new ReturnAST(std::shared_ptr<ExpressionAST>($2));
	}
	;

if:
	IF expression '{' block '}'
	{
		$$ = new IfAST(std::shared_ptr<ExpressionAST>($2),
		        std::shared_ptr<BlockAST>($4), std::shared_ptr<BlockAST>(nullptr));
	}
	| IF expression '{' block '}' ELSE '{' block '}'
	{
		$$ = new IfAST(std::shared_ptr<ExpressionAST>($2),
		        std::shared_ptr<BlockAST>($4), std::shared_ptr<BlockAST>($8));
	}
	;

print:
	PRINT expression
	{
		$$ = new PrintAST(std::shared_ptr<ExpressionAST>($2));
	}
	;

for:
	FOR IDENTIFIER ASSIGN expression ',' expression '{' block '}'
	{
		$$ = new ForAST(*$2, std::shared_ptr<ExpressionAST>($4), std::shared_ptr<ExpressionAST>($6),
				std::make_shared<IntegerAST>(1), std::shared_ptr<BlockAST>($8));
	}
	| FOR IDENTIFIER ASSIGN expression ',' expression ',' expression '{' block '}'
	{
		$$ = new ForAST(*$2, std::shared_ptr<ExpressionAST>($4), std::shared_ptr<ExpressionAST>($6),
				std::shared_ptr<ExpressionAST>($8), std::shared_ptr<BlockAST>($10));
	}
	;
