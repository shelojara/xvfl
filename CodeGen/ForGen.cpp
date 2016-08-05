#include "ForGen.hpp"

#include "../AST/FunctionAST.hpp"

llvm::Value * ForGen::emit(VflModule & module, ForAST & node)
{
    VarDeclAST initial(node.getVariable(), nullptr, node.getInitial());
    auto counter = initial.accept(demux);

    // create the block.
    auto function = module.getBuilder().GetInsertBlock()->getParent();
    auto block = llvm::BasicBlock::Create(llvm::getGlobalContext(), "forloop", function);
    auto after = llvm::BasicBlock::Create(llvm::getGlobalContext(), "forcont");
    auto condition = module.loadIfPtr(demux, node.getCondition());

    // fall to the block.
    module.getBuilder().CreateCondBr(condition, block, after);

    module.getBuilder().SetInsertPoint(block);

    module.createScope();
    node.getBlock()->accept(demux);
    module.popScope();

    // increment the counter.
    auto variable = module.getBuilder().CreateLoad(counter);
    auto result = module.getBuilder().CreateAdd(variable, module.loadIfPtr(demux, node.getIncrement()),
            "counter");
    module.getBuilder().CreateStore(result, counter);

    // execute again or stop.
    condition = node.getCondition()->accept(demux);
    module.getBuilder().CreateCondBr(condition, block, after);

    // insert the after block.
    function->getBasicBlockList().push_back(after);
    module.getBuilder().SetInsertPoint(after);

    return nullptr;
}
