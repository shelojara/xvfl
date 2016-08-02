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
    return binaryOpGen.emit(module, node);
}

llvm::Value * Demux::visit(FunctionCallAST & node)
{
    return functionCallGen.emit(module, node);
}

llvm::Value * Demux::visit(VersionInvAST & node)
{
    return functionCallGen.emit(module, node);
}

llvm::Value * Demux::visit(StringAST & node)
{
    return stringGen.emit(module, node);
}

llvm::Value * Demux::visit(IdentifierAST & node)
{
    return identifierGen.emit(module, node);
}

llvm::Value * Demux::visit(IntegerAST & node)
{
    return basicValueGen.emit(module, node);
}

llvm::Value * Demux::visit(BoolAST & node)
{
    return basicValueGen.emit(module, node);
}

llvm::Value * Demux::visit(FloatAST & node)
{
    return basicValueGen.emit(module, node);
}

llvm::Value * Demux::visit(ArrayAST & node)
{
    return arrayGen.emit(module, node);
}

llvm::Value * Demux::visit(ArrayIndexAST & node)
{
    return arrayGen.emit(module, node);
}

llvm::Value * Demux::visit(StructMemberAST & node)
{
    return structGen.emit(module, node);
}
