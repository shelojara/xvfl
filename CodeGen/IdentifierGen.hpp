#ifndef VFL_IDENTIFIERGEN_HPP
#define VFL_IDENTIFIERGEN_HPP


#include "Generator.hpp"
#include "../AST/ExpressionAST.hpp"
#include "../Demux/DemuxComponent.hpp"

class IdentifierGen : public DemuxComponent, public Generator<IdentifierAST>
{
public:
    virtual llvm::Value * emit(VflModule & module, IdentifierAST & node) override;
};


#endif //VFL_IDENTIFIERGEN_HPP
