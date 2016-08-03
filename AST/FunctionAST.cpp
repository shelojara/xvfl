#include "FunctionAST.hpp"

#include "../Demux/Demux.hpp"

std::string FunctionAST::virtualName(std::string name, std::string version)
{
    if (name.empty()) {
        throw std::runtime_error("Function needs a name.");
    }

    if (version.empty()) {
        return name;
    }

    return name + "." + version;
}

llvm::Value * FunctionAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

std::shared_ptr<Type> FunctionAST::getType()
{
    if (!type) {
        type.reset(new Type("void"));
    }

    return type;
}

llvm::Value * BlockAST::accept(Demux * demux)
{
    return demux->visit(*this);
}

const StatementList & BlockAST::getStatements() const
{
    return statements;
}

llvm::Value * ParameterAST::accept(Demux * demux)
{
    return demux->visit(*this);
}
