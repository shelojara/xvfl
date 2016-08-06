#ifndef VFL_BUILTINFUNCGEN_HPP
#define VFL_BUILTINFUNCGEN_HPP


#include "../Demux/DemuxComponent.hpp"
#include "Generator.hpp"
#include "../AST/StatementAST.hpp"

class BuiltInFuncGen : public DemuxComponent, public Generator<PrintAST>
{
public:
    virtual llvm::Value * emit(VflModule & module, PrintAST & node) override;
};


#endif //VFL_BUILTINFUNCGEN_HPP
