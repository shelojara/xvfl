#ifndef VFL_STATEMENTAST_HPP
#define VFL_STATEMENTAST_HPP

#include <string>

#include "NodeAST.hpp"
#include "ExpressionAST.hpp"

class BlockAST;
class StatementAST;
class Type;

typedef std::vector<std::shared_ptr<StatementAST>> StatementList;

class StatementAST : public NodeAST
{
public:
    virtual llvm::Value * accept(Demux * demux) override
    {
        return nullptr;
    }
};


/**
 * A for statement requires a variable, which will be declared in the outter scope,
 * an initial value for that variable, a continue condition, an increment, which
 * can be blank (defaulted to 1), and an execution block.
 */
class ForAST : public StatementAST
{
    std::string variable;
    std::shared_ptr<ExpressionAST> initial;
    std::shared_ptr<ExpressionAST> condition;
    std::shared_ptr<ExpressionAST> increment;
    std::shared_ptr<BlockAST> block;

public:
    ForAST(const std::string & variable, const std::shared_ptr<ExpressionAST> & initial,
           const std::shared_ptr<ExpressionAST> & condition,
           const std::shared_ptr<ExpressionAST> & increment,
           const std::shared_ptr<BlockAST> & block) :
            variable (variable), initial(initial), condition(condition),
            increment(increment), block(block)
    {}

    virtual llvm::Value * accept(Demux * demux) override;
};


/**
 * A variable declaration must have a name and expression or a type, the final
 * variable type is taken from the expression if the type is not explicitly
 * defined, if the type is defined, then the final type is that one, and the
 * expression is casted if there's one.
 */
class VarDeclAST : public StatementAST
{
    std::string name;
    std::shared_ptr<Type> type;
    std::shared_ptr<ExpressionAST> expression;

public:
    VarDeclAST(std::string name, std::shared_ptr<Type> type,
            std::shared_ptr<ExpressionAST> expression = nullptr) :
            name(name), type(type), expression(expression)
    {}

    virtual llvm::Value * accept(Demux * demux) override;
};


/**
 * An expression statement is an expression that is not enclosed inside
 * a statement, the most common case is a function call.
 */
class ExpressionStatementAST : public StatementAST
{
    std::shared_ptr<ExpressionAST> expression;

public:
    ExpressionStatementAST(std::shared_ptr<ExpressionAST> expression) :
            expression(expression)
    {}

    virtual llvm::Value * accept(Demux * demux) override;
};


class AssignmentAST : public StatementAST
{
    std::string variable;
    std::shared_ptr<ExpressionAST> expression;

public:
    AssignmentAST(std::string variable, std::shared_ptr<ExpressionAST> expression) :
            variable(variable), expression(expression)
    {}

    virtual llvm::Value * accept(Demux * demux) override;
};


class Return : public StatementAST
{
    std::shared_ptr<ExpressionAST> expression;

public:
    Return(std::shared_ptr<ExpressionAST> expression = nullptr) :
            expression(expression)
    {}

    virtual llvm::Value * accept(Demux * demux) override;
};


class IfAST : public StatementAST
{
    std::shared_ptr<ExpressionAST> condition;
    std::shared_ptr<BlockAST> thenBlock;
    std::shared_ptr<BlockAST> elseBlock;

public:
    IfAST(std::shared_ptr<ExpressionAST> condition,
          std::shared_ptr<BlockAST> thenBlock,
          std::shared_ptr<BlockAST> elseBlock) :
            condition(condition), thenBlock(thenBlock), elseBlock(elseBlock)
    {}

    virtual llvm::Value * accept(Demux * demux) override;
};


#endif //VFL_STATEMENTAST_HPP