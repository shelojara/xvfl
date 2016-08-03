#include "BasicValueGen.hpp"

llvm::Value * BasicValueGen::emit(VflModule & module, IntegerAST & node)
{
    return llvm::ConstantInt::get(llvm::Type::getInt32Ty(llvm::getGlobalContext()),
            (uint64_t) node.getValue(), true);
}

llvm::Value * BasicValueGen::emit(VflModule & module, FloatAST & node)
{
    return llvm::ConstantFP::get(llvm::Type::getFloatTy(llvm::getGlobalContext()), node.getValue());
}

llvm::Value * BasicValueGen::emit(VflModule & module, BoolAST & node)
{
    return llvm::ConstantInt::get(llvm::IntegerType::getInt1Ty(llvm::getGlobalContext()),
            (uint64_t) node.getValue(), false);
}

llvm::Value * BasicValueGen::emit(VflModule & module, ExpressionStatementAST & node)
{
    return node.getExpression()->accept(demux);
}
