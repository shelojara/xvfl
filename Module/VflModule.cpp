#include "VflModule.hpp"

#include "../Demux/Demux.hpp"
#include "../AST/ExpressionAST.hpp"
#include "../AST/FunctionAST.hpp"

llvm::Value * VflModule::loadIfPtr(Demux * demux, std::shared_ptr<ExpressionAST> node)
{
    auto value = node->accept(demux);

    if (value->getType()->isPointerTy()) {
        return builder.CreateLoad(value);
    }

    return value;
}

void VflModule::addFuncAlias(std::string name, std::string version, llvm::Function * function)
{
    std::string virtualName = FunctionAST::virtualName(name, version);
    funcAlias[virtualName] = function;
}
