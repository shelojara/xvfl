#ifndef VFL_STRUCTGEN_HPP
#define VFL_STRUCTGEN_HPP


#include "Generator.hpp"
#include "../AST/ExpressionAST.hpp"
#include "../Demux/DemuxComponent.hpp"
#include "../AST/StructAST.hpp"

class StructGen : public DemuxComponent, public Generator<StructMemberAST>,
                  public Generator<StructAST>
{
public:
    virtual llvm::Value * emit(VflModule & module, StructMemberAST & node) override;

    virtual llvm::Value * emit(VflModule & module, StructAST & node) override;
};


#endif //VFL_STRUCTGEN_HPP
