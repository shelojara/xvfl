#include "StatementAST.hpp"

llvm::Value * ForAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

llvm::Value * VarDeclAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

llvm::Value * ExpressionStatementAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

llvm::Value * AssignmentAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

llvm::Value * Return::accept(Demux * demux)
{
    return demux->visit(*this);
}

llvm::Value * IfAST::accept(Demux * demux)
{
    return demux->visit(*this);
}
