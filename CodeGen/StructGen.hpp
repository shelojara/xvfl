#ifndef VFL_STRUCTGEN_HPP
#define VFL_STRUCTGEN_HPP


#include "Generator.hpp"
#include "../AST/ExpressionAST.hpp"
#include "../Demux/DemuxComponent.hpp"

class StructGen : public DemuxComponent, public Generator<StructMemberAST>
{
public:
    virtual llvm::Value * emit(VflModule & module, StructMemberAST & node) override;
};


#endif //VFL_STRUCTGEN_HPP
