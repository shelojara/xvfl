/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VAR = 258,
     ASSIGN = 259,
     END = 260,
     RETURN = 261,
     IF = 262,
     ELSE = 263,
     PRINT = 264,
     VOID = 265,
     FOR = 266,
     TRUE = 267,
     FALSE = 268,
     PLUS = 269,
     MINUS = 270,
     MULT = 271,
     DIV = 272,
     EQ = 273,
     NEQ = 274,
     LESS = 275,
     GREATER = 276,
     LEQ = 277,
     GEQ = 278,
     MOD = 279,
     INTEGER = 280,
     FLOAT = 281,
     FUNCTION_NAME = 282,
     STRUCT_NAME = 283,
     IDENTIFIER = 284,
     STRING = 285
   };
#endif
/* Tokens.  */
#define VAR 258
#define ASSIGN 259
#define END 260
#define RETURN 261
#define IF 262
#define ELSE 263
#define PRINT 264
#define VOID 265
#define FOR 266
#define TRUE 267
#define FALSE 268
#define PLUS 269
#define MINUS 270
#define MULT 271
#define DIV 272
#define EQ 273
#define NEQ 274
#define LESS 275
#define GREATER 276
#define LEQ 277
#define GEQ 278
#define MOD 279
#define INTEGER 280
#define FLOAT 281
#define FUNCTION_NAME 282
#define STRUCT_NAME 283
#define IDENTIFIER 284
#define STRING 285




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 23 "Parser.y"
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
/* Line 1529 of yacc.c.  */
#line 126 "Generated/Parser.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

