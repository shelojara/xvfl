//
// Created by Marcelo Jara Almeyda on 8/2/16.
//

#ifndef VFL_IDENTIFIERGEN_HPP
#define VFL_IDENTIFIERGEN_HPP


#include "Generator.hpp"
#include "../AST/ExpressionAST.hpp"

class IdentifierGen : public Generator<IdentifierAST>
{
public:
    virtual llvm::Value * emit(VflModule & module, IdentifierAST & node) override;
};


#endif //VFL_IDENTIFIERGEN_HPP
