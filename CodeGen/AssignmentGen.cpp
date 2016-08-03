#include <iostream>
#include "AssignmentGen.hpp"

llvm::Value * AssignmentGen::emit(VflModule & module, AssignmentAST & node)
{
    auto ptr = node.getLeft()->accept(demux);
    auto value = module.loadIfPtr(demux, node.getRight());

    return module.getBuilder().CreateStore(value, ptr);
}
