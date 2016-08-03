#ifndef VFL_EXPRESSION_HPP
#define VFL_EXPRESSION_HPP


#include <memory>
#include <string>
#include <vector>

#include "NodeAST.hpp"
#include "../CodeGen/Generator.hpp"

class Demux;

class ExpressionAST;

typedef std::vector<std::shared_ptr<ExpressionAST>> ExpressionList;

/**
 * A general expression. An expression is by rule some operation
 * that should always return some value (even void).
 */
class ExpressionAST : NodeAST
{
public:
    virtual llvm::Value * accept(Demux * demux)
    {
        return nullptr;
    }
};


/**
 * Binary operations
 */
class BinaryOpAST : public ExpressionAST
{
    std::string op;

    std::shared_ptr<ExpressionAST> left;
    std::shared_ptr<ExpressionAST> right;

public:
    BinaryOpAST(std::shared_ptr<ExpressionAST> left, std::string op,
                std::shared_ptr<ExpressionAST> right) :
            op(op), left(left), right(right)
    {}

    const std::string & getOp() const;

    const std::shared_ptr<ExpressionAST> & getLeft() const;

    const std::shared_ptr<ExpressionAST> & getRight() const;

    virtual llvm::Value * accept(Demux * demux) override;
};


/**
 * Calls a function that has to be already defined, this could
 * return null.
 */
class FunctionCallAST : public ExpressionAST
{
    std::string name;
    std::string version;
    ExpressionList arguments;

public:
    FunctionCallAST(std::string name, std::string version, ExpressionList & arguments) :
            name(name), version(version), arguments(arguments)
    {}

    const std::string & getName() const;

    const std::string & getVersion() const;

    const ExpressionList & getArguments() const;

    std::string virtualName();

    virtual llvm::Value * accept(Demux * demux) override;
};


/**
 * Version Invocation.
 * Expression of the type @([version ';']...), which calls
 * the enclosing function, or a version of it.
 */
class VersionInvAST : public ExpressionAST
{
    std::string version;
    ExpressionList arguments;

public:
    VersionInvAST(std::string version, ExpressionList arguments) :
            version(version), arguments(arguments)
    {}

    const std::string & getVersion() const;

    const ExpressionList & getArguments() const;

    std::string virtualName(std::string name);

    virtual llvm::Value * accept(Demux * demux) override;
};


/**
 * String.
 */
class StringAST : public ExpressionAST
{
    std::string value;

public:
    StringAST(std::string value) : value(value)
    {}

    const std::string & getValue() const;

    virtual llvm::Value * accept(Demux * demux) override;
};


/**
 * A reference to an already defined scope value.
 */
class IdentifierAST : public ExpressionAST
{
    std::string name;

public:
    IdentifierAST(std::string name) :
            name(name)
    {}

    const std::string & getName() const;

    virtual llvm::Value * accept(Demux * demux) override;
};


class IntegerAST : public ExpressionAST
{
    int value;

public:
    IntegerAST(int value) :
            value(value)
    {}

    int getValue() const;

    virtual llvm::Value * accept(Demux * demux) override;
};


class BoolAST : public ExpressionAST
{
    bool boolean;

public:
    BoolAST(bool boolean) :
            boolean(boolean)
    {}

    bool isBoolean() const;

    virtual llvm::Value * accept(Demux * demux) override;
};


class FloatAST : public ExpressionAST
{
    float value;

public:
    FloatAST(float value) :
            value(value)
    {}

    float getValue() const;

    virtual llvm::Value * accept(Demux * demux) override;
};


class ArrayAST : public ExpressionAST
{
    ExpressionList elements;

public:
    ArrayAST(ExpressionList elements) :
            elements(elements)
    {}

    const ExpressionList & getElements() const;

    virtual llvm::Value * accept(Demux * demux) override;
};


struct ArrayIndexAST : public ExpressionAST
{
    std::string name;
    std::shared_ptr<ExpressionAST> expression;

public:
    ArrayIndexAST(std::string name, std::shared_ptr<ExpressionAST> expression) :
            name(name), expression(expression)
    {}

    const std::string & getName() const;

    const std::shared_ptr<ExpressionAST> & getExpression() const;

    virtual llvm::Value * accept(Demux * demux) override;
};


/**
 * An struct member refers to a named value taken from another
 * expression (that returns a Struct).
 */
class StructMemberAST : public ExpressionAST
{
    std::string variable;
    std::string member;

public:
    StructMemberAST(std::string variable, std::string member) :
            variable(variable), member(member)
    {}

    const std::string & getVariable() const;

    const std::string & getMember() const;

    virtual llvm::Value * accept(Demux * demux) override;
};


#endif // VFL_EXPRESSION_HPP
