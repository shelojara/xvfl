#include "StringGen.hpp"

llvm::Value * StringGen::emit(VflModule & module, StringAST & node)
{
    auto constString = llvm::ConstantDataArray::getString(llvm::getGlobalContext(),
            node.getValue());

    auto var = new llvm::GlobalVariable(*module.getLLVMModule(),
            llvm::ArrayType::get(llvm::IntegerType::get(llvm::getGlobalContext(), 8),
                    node.getValue().length() + 1),
            true, llvm::GlobalValue::PrivateLinkage, constString, ".str");

    auto zero = llvm::Constant::getNullValue(module.getTypeSystem().intTy);

    return module.getBuilder().CreateInBoundsGEP(var, { zero, zero });
}
