#include "Demux.hpp"

#include "../CodeGen/FunctionGen.hpp"
#include "../AST/Program.hpp"

void Demux::walkAST(Program & program)
{
    // FIXME: this method should provably be it's own class.

    module.addFuncAlias("Print", "format", llvm::dyn_cast<llvm::Function>(
            module.getLLVMModule()->getOrInsertFunction("printf", llvm::FunctionType::get(
                    module.getTypeSystem().intTy,
                    llvm::PointerType::get(module.getTypeSystem().charTy, 0),
                    true
            ))));

    // emit all structs.
    for (auto structDef : program.getStructList()) {
        structDef->accept(this);
    }

    // emit all functions.
    for (auto function : program.getFunctionList()) {
        function->accept(this);
    }
}

llvm::Value * Demux::visit(FunctionAST & node)
{
    return functionGen.emit(module, node);
}

llvm::Value * Demux::visit(BlockAST & node)
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

llvm::Value * Demux::visit(ForAST & node)
{
    return forGen.emit(module, node);
}

llvm::Value * Demux::visit(VarDeclAST & node)
{
    return varDeclGen.emit(module, node);
}

llvm::Value * Demux::visit(ExpressionStatementAST & node)
{
    return basicValueGen.emit(module, node);
}

llvm::Value * Demux::visit(AssignmentAST & node)
{
    return assignmentGen.emit(module, node);
}

llvm::Value * Demux::visit(ReturnAST & node)
{
    return functionGen.emit(module, node);
}

llvm::Value * Demux::visit(IfAST & node)
{
    return ifGen.emit(module, node);
}

llvm::Value * Demux::visit(PrintAST & node)
{
    return builtInFuncGen.emit(module, node);
}

llvm::Value * Demux::visit(ParameterAST & node)
{
    return functionGen.emit(module, node);
}

llvm::Value * Demux::visit(StructAST & node)
{
    return structGen.emit(module, node);
}
