#ifndef VFL_FORGEN_HPP
#define VFL_FORGEN_HPP


#include "../Demux/DemuxComponent.hpp"
#include "Generator.hpp"
#include "../AST/StatementAST.hpp"

class ForGen : public DemuxComponent, public Generator<ForAST>
{
public:
    virtual llvm::Value * emit(VflModule & module, ForAST & node) override;
};


#endif //VFL_FORGEN_HPP
