#ifndef VFL_ARRAYGEN_HPP
#define VFL_ARRAYGEN_HPP


#include "Generator.hpp"
#include "../AST/ExpressionAST.hpp"

class ArrayGen : public Generator<ArrayAST>, public Generator<ArrayIndexAST>
{
public:
    virtual llvm::Value * emit(VflModule & module, ArrayIndexAST & node) override;

    virtual llvm::Value * emit(VflModule & module, ArrayAST & node) override;
};


#endif //VFL_ARRAYGEN_HPP
