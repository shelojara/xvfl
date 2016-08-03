#ifndef VFL_VFLMODULE_HPP
#define VFL_VFLMODULE_HPP

#include <llvm/IR/Module.h>
#include "../Util/NonCopyable.hpp"
#include <llvm/IR/IRBuilder.h>
#include "../TypeSystem/TypeSystem.hpp"
#include "Scope.hpp"

class FunctionAST;


class VflModule : private NonCopyable
{
private:
    llvm::Module * llvmModule;

    TypeSystem typeSystem;

    llvm::IRBuilder<> builder;

    std::vector<std::shared_ptr<Scope>> scopes;

    FunctionAST * lastFunction;

    std::map<std::string, llvm::Function*> funcAlias;

public:
    VflModule() :
            llvmModule(new llvm::Module("main", llvm::getGlobalContext())),
            builder(llvm::getGlobalContext())
    {}

    llvm::Module * getLLVMModule() const
    {
        return llvmModule;
    }

    TypeSystem & getTypeSystem()
    {
        return typeSystem;
    }

    void setLastFunction(FunctionAST * lastFunction)
    {
        VflModule::lastFunction = lastFunction;
    }

    FunctionAST * getLastFunction() const
    {
        return lastFunction;
    }

    llvm::IRBuilder<> & getBuilder()
    {
        return builder;
    }

    std::shared_ptr<Scope> getScope() const
    {
        return scopes.back();
    }

    void createScope()
    {
        Scope * parent = nullptr;

        if (!scopes.empty()) {
            parent = scopes.back().get();
        }

        scopes.push_back(std::make_shared<Scope>(parent));
    }

    void popScope()
    {
        scopes.pop_back();
    }
};


#endif //VFL_VFLMODULE_HPP
