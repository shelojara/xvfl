#include <iostream>
#include "StructGen.hpp"

#include "../AST/FunctionAST.hpp"

llvm::Value * StructGen::emit(VflModule & module, StructAST & node)
{
    std::vector<llvm::Type*> memberTypes;
    std::vector<std::string> members;

    auto structType = llvm::StructType::create(llvm::getGlobalContext(), node.getName());
    module.getTypeSystem().addStructType(node.getName(), structType);

    for (auto member : node.getMembers()) {
        members.push_back(member->getName());
        memberTypes.push_back(member->getType()->toLLVM(module.getTypeSystem()));
    }

    if (structType->isOpaque()) {
        structType->setBody(memberTypes, false);
    }

    module.getTypeSystem().setStructMembers(node.getName(), members);

    return nullptr;
}

llvm::Value * StructGen::emit(VflModule & module, StructMemberAST & node)
{
    auto left = node.getLeft()->accept(demux);

    if (!left->getType()->isPointerTy()) {
        // FIXME
        throw std::runtime_error("This type can't hold a struct.");
    }

    auto structPtr = module.getBuilder().CreateLoad(left);

    auto underlyingStruct = new llvm::LoadInst(structPtr);

    if (!underlyingStruct->getType()->isStructTy()) {
        throw std::runtime_error("This is not a struct.");
    }

    std::string name = underlyingStruct->getType()->getStructName().str();
    int memberIndex = module.getTypeSystem().getStructMemberIndex(name, node.getMember());

    auto zero = llvm::ConstantInt::get(module.getTypeSystem().intTy, 0, true);
    auto index = llvm::ConstantInt::get(module.getTypeSystem().intTy, (uint64_t) memberIndex, true);

    // return the pointer to the member.
    return module.getBuilder().CreateInBoundsGEP(structPtr, { zero, index });
}
