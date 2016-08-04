#include "FunctionCallGen.hpp"

#include "../AST/FunctionAST.hpp"

llvm::Value * FunctionCallGen::makeFunctionCall(VflModule & module,
        ExpressionList & arguments, llvm::Function * function)
{
    // TODO: check for arg compatibility.

    std::vector<llvm::Value *> values;
    for (auto i : arguments) {
        auto value = module.loadIfPtr(demux, i);

        // variadic function promotion.
        if (function->isVarArg() && value->getType()->isFloatTy()) {
            value = module.getTypeSystem().cast(value,
                    module.getTypeSystem().doubleTy, module.getBuilder().GetInsertBlock());
        }

        values.push_back(value);
    }

    return module.getBuilder().CreateCall(function, values);
}

llvm::Value * FunctionCallGen::emit(VflModule & module, FunctionCallAST & node)
{
    auto function = module.getLLVMModule()->getFunction(node.virtualName());

    if (function == nullptr) {
        function = module.getFuncAlias(node.virtualName());
    }

    return makeFunctionCall(module, node.getArguments(), function);
}

llvm::Value * FunctionCallGen::emit(VflModule & module, VersionInvAST & node)
{
    auto name = (std::string) module.getLastFunction()->getName();
    auto virtualName = node.virtualName(name);
    auto function = module.getLLVMModule()->getFunction(virtualName);

    if (function == nullptr) {
        throw std::runtime_error("Function not defined: " + name);
    }

    return makeFunctionCall(module, node.getArguments(), function);
}
