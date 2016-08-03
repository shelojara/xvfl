#include <iostream>
#include "AssignmentGen.hpp"

llvm::Value * AssignmentGen::emit(VflModule & module, AssignmentAST & node)
{
    auto target = node.getLeft()->accept(demux);

    return module.getBuilder().CreateStore(node.getRight()->accept(demux), target);
}
