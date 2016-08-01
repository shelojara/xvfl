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
    BinaryOpAST(const std::string & op, const std::shared_ptr<ExpressionAST> & left,
                const std::shared_ptr<ExpressionAST> & right) : op(op), left(left), right(right)
    {}

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
    FunctionCallAST(std::string & name, std::string & version, ExpressionList & arguments) :
            name(name), version(version), arguments(arguments)
    {}

    std::string virtualName();

    virtual llvm::Value * accept(Demux * demux) override;
};


/**
 * Version Invocation.
 * Expression of the type @([version ';']...), which calls
 * the enclosing function, or a version of it.
 */
class VersionInv : public ExpressionAST
{
    std::string version;
    ExpressionList arguments;

public:
    VersionInv(std::string version, ExpressionList arguments) :
            version(version), arguments(arguments)
    {}

    std::string virtualName(std::string name);

    virtual llvm::Value * accept(Demux * demux) override;
};


/**
 * String.
 */
class String : public ExpressionAST
{
    std::string value;

public:
    String(std::string value) : value(value)
    {}

    virtual llvm::Value * accept(Demux * demux) override;
};


/**
 * A reference to an already defined scope value.
 */
class Identifier : public ExpressionAST
{
    std::string name;

public:
    Identifier(std::string name) :
            name(name)
    {}

    virtual llvm::Value * accept(Demux * demux) override;
};


class Integer : public ExpressionAST
{
    int value;

public:
    Integer(int value) :
            value(value)
    {}

    virtual llvm::Value * accept(Demux * demux) override;
};


class Bool : public ExpressionAST
{
    bool boolean;

public:
    Bool(bool boolean) :
            boolean(boolean)
    {}

    virtual llvm::Value * accept(Demux * demux) override;
};


class Float : public ExpressionAST
{
    float value;

public:
    Float(float value) : value(value) {}
    virtual ~Float() = default;

    virtual llvm::Value * accept(Generator * generator);
};


#endif // VFL_EXPRESSION_HPP
