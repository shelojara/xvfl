#ifndef VFL_STRUCTGEN_HPP
#define VFL_STRUCTGEN_HPP


#include "Generator.hpp"
#include "../AST/ExpressionAST.hpp"

class StructGen : public Generator<StructMemberAST>
{
public:
    virtual llvm::Value * emit(VflModule & module, StructMemberAST & node) override;
};


#endif //VFL_STRUCTGEN_HPP
