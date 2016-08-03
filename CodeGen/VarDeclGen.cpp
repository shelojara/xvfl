#include "VarDeclGen.hpp"
#include "../TypeSystem/Types.hpp"

llvm::Value * VarDeclGen::emit(VflModule & module, VarDeclAST & node)
{
    llvm::Value * initial = nullptr;

    if (node.getExpression()) {
        initial = module.loadIfPtr(demux, node.getExpression());
    }

    llvm::Value * value = nullptr;

    bool hasDefinedType = node.getType() != nullptr;

    llvm::Type * type = nullptr;

    if (!node.getType()) {
        if (initial == nullptr) {
            throw std::runtime_error("Variable type inference needs a definition.");
        }

        type = initial->getType();
    } else {
        type = node.getType()->toLLVM(module.getTypeSystem());
    }

    if (node.getType() && node.getType()->isArray()) {
        // if this is an array, we should allocate it and then fake it as an initial value.
        auto arrayType = reinterpret_cast<ArrayType*>(node.getType().get());
        auto arraySize = arrayType->getSize()->accept(demux);
        initial = module.getBuilder().CreateAlloca(type->getArrayElementType(), arraySize);
        type = initial->getType();

        // this flag has to be disabled, since arrays cannot be casted.
        hasDefinedType = false;
    }

    if (node.getType() && node.getType()->isStruct()) {
        // if this is a struct, we should allocate it and then fake it as an initial value.
        auto structType = module.getTypeSystem().getStructType(node.getType()->getName());
        initial = module.getBuilder().CreateAlloca(structType);
        type = initial->getType();

        // this flag has to be disabled, since structs cannot be casted.
        hasDefinedType = false;
    }

    value = module.getBuilder().CreateAlloca(type, nullptr, node.getName());

    if (initial != nullptr) {
        if (hasDefinedType) {
            initial = module.getTypeSystem().cast(initial,
                    node.getType()->toLLVM(module.getTypeSystem()),
                    module.getBuilder().GetInsertBlock());
        }

        module.getBuilder().CreateStore(initial, value);
    }

    module.getScope()->add(node.getName(), value);
    return value;
}
