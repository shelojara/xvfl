#include "FunctionGen.hpp"

#include "../AST/FunctionAST.hpp"


llvm::Value * FunctionGen::emit(VflModule & module, FunctionAST & node)
{
    node.getBlock()->accept(demux);
    return nullptr;
}

llvm::Value * FunctionGen::emit(VflModule & module, BlockAST & node)
{
    return nullptr;
}
