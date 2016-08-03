#include "ExpressionAST.hpp"

#include "FunctionAST.hpp"
#include "../Demux/Demux.hpp"

std::string FunctionCallAST::virtualName()
{
    return FunctionAST::virtualName(name, version);
}

std::string VersionInvAST::virtualName(std::string name)
{
    return FunctionAST::virtualName(name, version);
}

llvm::Value * BinaryOpAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

const std::string & BinaryOpAST::getOp() const
{
    return op;
}

const std::shared_ptr<ExpressionAST> & BinaryOpAST::getLeft() const
{
    return left;
}

const std::shared_ptr<ExpressionAST> & BinaryOpAST::getRight() const
{
    return right;
}

llvm::Value * FunctionCallAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

const ExpressionList & FunctionCallAST::getArguments() const
{
    return arguments;
}

llvm::Value * VersionInvAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

const std::string & VersionInvAST::getVersion() const
{
    return version;
}

const ExpressionList & VersionInvAST::getArguments() const
{
    return arguments;
}

llvm::Value * StringAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

llvm::Value * IdentifierAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

const std::string & IdentifierAST::getName() const
{
    return name;
}

llvm::Value * IntegerAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

int IntegerAST::getValue() const
{
    return value;
}

llvm::Value * BoolAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

llvm::Value * FloatAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

float FloatAST::getValue() const
{
    return value;
}

llvm::Value * ArrayAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

const ExpressionList & ArrayAST::getElements() const
{
    return elements;
}

llvm::Value * ArrayIndexAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

const std::string & ArrayIndexAST::getName() const
{
    return name;
}

const std::shared_ptr<ExpressionAST> & ArrayIndexAST::getExpression() const
{
    return expression;
}

llvm::Value * StructMemberAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

const std::string & StructMemberAST::getMember() const
{
    return member;
}

const std::shared_ptr<ExpressionAST> & StructMemberAST::getLeft() const
{
    return left;
}
