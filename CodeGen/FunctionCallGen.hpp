#ifndef VFL_FUNCTIONCALLGEN_HPP
#define VFL_FUNCTIONCALLGEN_HPP


#include "Generator.hpp"
#include "../AST/ExpressionAST.hpp"
#include "../Demux/DemuxComponent.hpp"

class FunctionCallGen : public DemuxComponent, public Generator<FunctionCallAST>, public Generator<VersionInvAST>
{
public:
    virtual llvm::Value * emit(VflModule & module, FunctionCallAST & node) override;
    virtual llvm::Value * emit(VflModule & module, VersionInvAST & node) override;
};


#endif //VFL_FUNCTIONCALLGEN_HPP
