#ifndef VFL_FUNCTION_HPP
#define VFL_FUNCTION_HPP

#include <llvm/IR/Value.h>
#include <vector>
#include <string>

#include "ExpressionAST.hpp"
#include "StatementAST.hpp"

class Demux;
class FunctionAST;

typedef std::vector<std::shared_ptr<FunctionAST>> FunctionList;


class FunctionAST : public NodeAST
{
    std::string name;
    ExpressionList expressions;

public:
    FunctionAST(const std::string & name, const ExpressionList & expressions) :
            name(name), expressions(expressions) {}

    static std::string virtualName(std::string name, std::string version);

    virtual llvm::Value * accept(Demux * demux) override;
};


class BlockAST : public NodeAST
{
    StatementList statements;

public:
    BlockAST(StatementList & statements) :
            statements(statements)
    {}

    virtual llvm::Value * accept(Demux * demux) override;
};

#endif // VFL_FUNCTION_HPP
