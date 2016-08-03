#ifndef VFL_VARDECLGEN_HPP
#define VFL_VARDECLGEN_HPP


#include "Generator.hpp"
#include "../AST/StatementAST.hpp"
#include "../Demux/DemuxComponent.hpp"

class VarDeclGen : public Generator<VarDeclAST>, public DemuxComponent
{
public:
    virtual llvm::Value * emit(VflModule & module, VarDeclAST & node) override;
};


#endif //VFL_VARDECLGEN_HPP
