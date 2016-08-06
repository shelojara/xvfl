#include "IfGen.hpp"

#include "../AST/FunctionAST.hpp"

llvm::Value * IfGen::emit(VflModule & module, IfAST & node)
{
    auto condition = module.loadIfPtr(demux, node.getCondition());

    auto function = module.getBuilder().GetInsertBlock()->getParent();

    auto thenBlock = llvm::BasicBlock::Create(llvm::getGlobalContext(), "then", function);
    auto elseBlock = llvm::BasicBlock::Create(llvm::getGlobalContext(), "else");
    auto mergeBlock = llvm::BasicBlock::Create(llvm::getGlobalContext(), "ifcont");

    if (node.getElseBlock()) {
        module.getBuilder().CreateCondBr(condition, thenBlock, elseBlock);
    } else {
        module.getBuilder().CreateCondBr(condition, thenBlock, mergeBlock);
    }

    module.getBuilder().SetInsertPoint(thenBlock);

    module.createScope();
    node.getThenBlock()->accept(demux);
    module.popScope();

    thenBlock = module.getBuilder().GetInsertBlock();

    if (thenBlock->getTerminator() == nullptr) {
        module.getBuilder().CreateBr(mergeBlock);
    }

    if (node.getElseBlock()) {
        function->getBasicBlockList().push_back(elseBlock);
        module.getBuilder().SetInsertPoint(elseBlock);

        module.createScope();
        node.getElseBlock()->accept(demux);
        module.popScope();

        module.getBuilder().CreateBr(mergeBlock);
    }

    function->getBasicBlockList().push_back(mergeBlock);
    module.getBuilder().SetInsertPoint(mergeBlock);

    return nullptr;
}
