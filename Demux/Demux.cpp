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
    return nullptr; // binaryOpGen.emit(*module, node);
}

llvm::Value * Demux::visit(FunctionCallAST & node)
{
    return nullptr; // functionCallGen.emit(*module, node);
}

llvm::Value * Demux::visit(VersionInvAST & node)
{
    return nullptr; // versionInvGen.emit(*module, node);
}

llvm::Value * Demux::visit(StringAST & node)
{
    return nullptr; // stringGen.emit(*module, node);
}

llvm::Value * Demux::visit(IdentifierAST & node)
{
    return nullptr; // identifierGen.emit(*module, node);
}

llvm::Value * Demux::visit(IntegerAST & node)
{
    return nullptr; // basicValueGen.emitInteger(*module, node);
}

llvm::Value * Demux::visit(BoolAST & node)
{
    return nullptr; // basicValueGen.emitBool(*module, node);
}

llvm::Value * Demux::visit(FloatAST & node)
{
    return nullptr; // basicValueGen.emitFloat(*module, node);
}

llvm::Value * Demux::visit(ArrayAST & node)
{
    return nullptr; // arrayGen.emit(*module, node);
}

llvm::Value * Demux::visit(ArrayIndexAST & node)
{
    return nullptr; // arrayIndexGen.emit(*module, node);
}

llvm::Value * Demux::visit(StructMemberAST & node)
{
    return nullptr; // structMemberGen.emit(*module, node);
}
