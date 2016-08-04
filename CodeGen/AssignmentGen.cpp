#include <memory>
#include "AssignmentGen.hpp"

llvm::Value * AssignmentGen::emit(VflModule & module, AssignmentAST & node)
{
    auto left = node.getLeft()->accept(demux);

    // check that the lvalue is a variable.
    if (!left->getType()->isPointerTy()) {
        throw std::runtime_error("Lvalue is not a pointer.");
    }

    auto value = module.loadIfPtr(demux, node.getRight());

    // check type of pointer and value are the same.
    auto underlyingValue = std::unique_ptr<llvm::LoadInst>(new llvm::LoadInst(left));

    if (underlyingValue->getType() != value->getType()) {
        throw std::runtime_error(
                "Can't assign " + std::to_string(left->getType()->getTypeID()) +
                        " to " + std::to_string(underlyingValue->getType()->getTypeID()));
    }

    // store the value.
    return module.getBuilder().CreateStore(value, left);
}
