#include "IdentifierGen.hpp"

#include <iostream>

llvm::Value * IdentifierGen::emit(VflModule & module, IdentifierAST & node)
{
    auto value = module.getScope()->get(node.getName());

    if (value == nullptr) {
        throw std::runtime_error("Symbol not defined: " + node.getName());
    }

    return value;
}
