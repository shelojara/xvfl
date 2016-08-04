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

    virtual llvm::Value * accept(Demux * demux) override;

    std::string getOp() const
    {
        return op;
    }

    std::shared_ptr<ExpressionAST> getLeft()
    {
        return left;
    }

    std::shared_ptr<ExpressionAST> getRight()
    {
        return right;
    }
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

    virtual llvm::Value * accept(Demux * demux) override;

    std::string getName() const
    {
        return name;
    }

    std::string getVersion() const
    {
        return version;
    }

    ExpressionList & getArguments()
    {
        return arguments;
    }

    std::string virtualName();
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

    virtual llvm::Value * accept(Demux * demux) override;

    std::string getVersion() const
    {
        return version;
    }

    ExpressionList & getArguments()
    {
        return arguments;
    }

    std::string virtualName(std::string name);
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

    virtual llvm::Value * accept(Demux * demux) override;

    std::string getValue() const
    {
        return value;
    }
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

    virtual llvm::Value * accept(Demux * demux) override;

    std::string getName() const
    {
        return name;
    }
};


class IntegerAST : public ExpressionAST
{
    int value;

public:
    IntegerAST(int value) :
            value(value)
    {}

    virtual llvm::Value * accept(Demux * demux) override;

    int getValue()
    {
        return value;
    }
};


class BoolAST : public ExpressionAST
{
    bool value;

public:
    BoolAST(bool value) :
            value(value)
    {}

    virtual llvm::Value * accept(Demux * demux) override;

    bool getValue() const
    {
        return value;
    }
};


class FloatAST : public ExpressionAST
{
    float value;

public:
    FloatAST(float value) :
            value(value)
    {}

    virtual llvm::Value * accept(Demux * demux) override;

    float getValue()
    {
        return value;
    }
};


class ArrayAST : public ExpressionAST
{
    ExpressionList elements;

public:
    ArrayAST(ExpressionList elements) :
            elements(elements)
    {}

    virtual llvm::Value * accept(Demux * demux) override;

    ExpressionList & getElements()
    {
        return elements;
    }
};


struct ArrayIndexAST : public ExpressionAST
{
    std::shared_ptr<ExpressionAST> left;
    std::shared_ptr<ExpressionAST> index;

public:
    ArrayIndexAST(std::shared_ptr<ExpressionAST> left, std::shared_ptr<ExpressionAST> index) :
            left(left), index(index)
    {}

    virtual llvm::Value * accept(Demux * demux) override;

    std::shared_ptr<ExpressionAST> getLeft() const
    {
        return left;
    }

    std::shared_ptr<ExpressionAST> getIndex()
    {
        return index;
    }
};


/**
 * An struct member refers to a named value taken from another
 * expression (that returns a Struct).
 */
class StructMemberAST : public ExpressionAST
{
    std::shared_ptr<ExpressionAST> left;
    std::string member;

public:
    StructMemberAST(std::shared_ptr<ExpressionAST> left, std::string member) :
            left(left), member(member)
    {}

    virtual llvm::Value * accept(Demux * demux) override;

    std::string getMember()
    {
        return member;
    }

    std::shared_ptr<ExpressionAST> getLeft() const
    {
        return left;
    }
};


#endif // VFL_EXPRESSION_HPP
