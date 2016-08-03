#include "Types.hpp"


llvm::Type * Type::getType(TypeSystem & typeSystem)
{
    if (name == "int") {
        return typeSystem.intTy;
    }

    if (name == "float") {
        return typeSystem.floatTy;
    }

    if (name == "string") {
        return typeSystem.stringTy;
    }

    if (name == "bool") {
        return typeSystem.boolTy;
    }

    return typeSystem.voidTy;
}


llvm::Type * ArrayType::getType(TypeSystem & typeSystem)
{
    return llvm::PointerType::get(Type::getType(typeSystem), 0);
}


llvm::Type * StructType::getType(TypeSystem & typeSystem)
{
    return llvm::PointerType::get(typeSystem.getStructType(name), 0);
}
