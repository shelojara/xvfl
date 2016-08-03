#include "FunctionCallGen.hpp"

llvm::Value * FunctionCallGen::emit(VflModule & module, FunctionCallAST & node)
{
    auto function = module.getLLVMModule()->getFunction(node.virtualName());

    if (function == nullptr) {
        function = module.getFuncAlias(node.virtualName());
    }

    // TODO: check arg compatibility.

    std::vector<llvm::Value *> values;
    for (auto i : node.getArguments()) {
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

llvm::Value * FunctionCallGen::emit(VflModule & module, VersionInvAST & node)
{
    return nullptr;
}
