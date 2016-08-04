#include "FunctionGen.hpp"


std::vector<llvm::Type *> makeParameterTypes(TypeSystem & typeSystem,
        ParameterList parameters)
{
    std::vector<llvm::Type*> types;

    for (auto i : parameters) {
        types.push_back(i->getType()->toLLVM(typeSystem));
    }

    return types;
}


void FunctionGen::loadParameters(VflModule & module,
        llvm::iterator_range<llvm::Function::arg_iterator> args,
        ParameterList parameters)
{
    int i = 0;
    for (auto & arg : args) {
        auto parameter = parameters[i++];
        arg.setName("param." + parameter->getName());

        auto value = parameter->accept(demux);
        module.getBuilder().CreateStore(&arg, value);

        module.getScope()->add(parameter->getName(), value);
    }
}


llvm::Value * FunctionGen::emit(VflModule & module, FunctionAST & node)
{
    // get virtual name of the function for LLVM.
    std::string name = node.getName() == "Main" ? "main" : node.virtualName();

    auto parameterTypes = makeParameterTypes(module.getTypeSystem(), node.getParameters());
    auto type = llvm::FunctionType::get(node.getType()->toLLVM(module.getTypeSystem()),
            parameterTypes, false);

    auto function = llvm::Function::Create(type, llvm::Function::ExternalLinkage, name,
            module.getLLVMModule());

    module.setLastFunction(&node);

    // create the block for this function.
    module.getBuilder().SetInsertPoint(llvm::BasicBlock::Create(llvm::getGlobalContext(),
            "entry", function));

    // create the scope.
    module.createScope();

    // load everything on the scope, including parameters and code block.
    loadParameters(module, function->args(), node.getParameters());

    node.getBlock()->accept(demux);

    if (module.getBuilder().GetInsertBlock()->getTerminator() == nullptr) {
        module.getBuilder().CreateRetVoid();
    }

    module.popScope();

    return function;
}

llvm::Value * FunctionGen::emit(VflModule & module, BlockAST & node)
{
    for (auto statement : node.getStatements()) {
        statement->accept(demux);
    }

    return nullptr;
}

llvm::Value * FunctionGen::emit(VflModule & module, ParameterAST & node)
{
    return module.getBuilder().CreateAlloca(node.getType()->toLLVM(module.getTypeSystem()),
            nullptr, node.getName());
}
