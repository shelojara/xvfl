#include "Demux.hpp"

#include "../CodeGen/FunctionGen.hpp"
#include "../AST/Program.hpp"

void Demux::walkAST(Program * program)
{
    // FIXME: this method should provably be it's own class.

    // emit all the functions.
    for (auto function : program->getFunctionList()) {
        function->accept(this);
    }
}

llvm::Value * Demux::visit(FunctionAST & node)
{
    return functionGen.emit(module, node);
}

llvm::Value * Demux::visit(BinaryOpAST & node)
{
    return nullptr;
}

llvm::Value * Demux::visit(FunctionCallAST & node)
{
    return nullptr;
}
