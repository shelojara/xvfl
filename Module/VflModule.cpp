#include "VflModule.hpp"

#include "../Demux/Demux.hpp"
#include "../AST/ExpressionAST.hpp"

llvm::Value * VflModule::loadIfPtr(Demux * demux, std::shared_ptr<ExpressionAST> node)
{
    auto value = node->accept(demux);

    if (value->getType()->isPointerTy()) {
        return builder.CreateLoad(value);
    }

    return value;
}
