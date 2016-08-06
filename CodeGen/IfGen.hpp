#ifndef VFL_IFGEN_HPP
#define VFL_IFGEN_HPP


#include "../Demux/DemuxComponent.hpp"
#include "Generator.hpp"
#include "../AST/StatementAST.hpp"

class IfGen : public DemuxComponent, public Generator<IfAST>
{
public:
    virtual llvm::Value * emit(VflModule & module, IfAST & node) override;
};


#endif //VFL_IFGEN_HPP
