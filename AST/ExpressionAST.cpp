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

llvm::Value * FunctionCallAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

llvm::Value * VersionInvAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

llvm::Value * StringAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

llvm::Value * IdentifierAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

llvm::Value * IntegerAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

llvm::Value * BoolAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

llvm::Value * FloatAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

llvm::Value * ArrayAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

llvm::Value * ArrayIndexAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

llvm::Value * StructMemberAST::accept(Demux * demux)
{
    return demux->visit(*this);
}
