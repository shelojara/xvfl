#ifndef VFL_TYPESYSTEM_HPP
#define VFL_TYPESYSTEM_HPP

#include <memory>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Type.h>
#include "../Util/NonCopyable.hpp"


class TypeSystem : private NonCopyable
{
    llvm::Type * intTy = (llvm::Type *) llvm::Type::getInt32Ty(llvm::getGlobalContext());
    llvm::Type * floatTy = llvm::Type::getFloatTy(llvm::getGlobalContext());
};


#endif //VFL_TYPESYSTEM_HPP
