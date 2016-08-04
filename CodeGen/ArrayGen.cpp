
#include "ArrayGen.hpp"

llvm::Value * ArrayGen::emit(VflModule & module, ArrayAST & node)
{
    auto first = module.loadIfPtr(demux, node.getElements()[0]);

    auto size = llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvm::getGlobalContext()),
            node.getElements().size(), true);

    auto array = module.getBuilder().CreateAlloca(first->getType(), size);

    uint i = 0;
    for (auto e : node.getElements()) {
        auto value = module.loadIfPtr(demux, e);
        auto index = llvm::ConstantInt::get(module.getTypeSystem().intTy, i, true);
        auto ptr = llvm::GetElementPtrInst::CreateInBounds(array, { index }, "",
                module.getBuilder().GetInsertBlock());
        module.getBuilder().CreateStore(value, ptr);
        i++;
    }

    llvm::Value * arrayPtr = module.getBuilder().CreateAlloca(array->getType());
    module.getBuilder().CreateStore(array, arrayPtr);

    return arrayPtr;
}

llvm::Value * ArrayGen::emit(VflModule & module, ArrayIndexAST & node)
{
    auto array = node.getLeft()->accept(demux);

    auto index = module.loadIfPtr(demux, node.getIndex());

    auto ptr = llvm::GetElementPtrInst::CreateInBounds(array, {index}, "",
            module.getBuilder().GetInsertBlock());

    return module.getBuilder().CreateLoad(ptr);
}
