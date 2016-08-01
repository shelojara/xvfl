#include "ExpressionAST.hpp"

#include "FunctionAST.hpp"
#include "../Demux/Demux.hpp"

std::string FunctionCallAST::virtualName()
{
    return FunctionAST::virtualName(name, version);
}

std::string VersionInv::virtualName(std::string name)
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

llvm::Value * VersionInv::accept(Demux * demux)
{
    return demux->visit(*this);
}

llvm::Value * String::accept(Demux * demux)
{
    return demux->visit(*this);
}

llvm::Value * Identifier::accept(Demux * demux)
{
    return demux->visit(*this);
}

llvm::Value * Integer::accept(Demux * demux)
{
    return demux->visit(*this);
}

llvm::Value * Bool::accept(Demux * demux)
{
    return demux->visit(*this);
}
