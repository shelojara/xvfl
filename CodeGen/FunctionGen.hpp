#ifndef VFL_FUNCTIONGEN_HPP
#define VFL_FUNCTIONGEN_HPP

#include <llvm/IR/Value.h>

#include "Generator.hpp"
#include "../Demux/DemuxComponent.hpp"
#include "../AST/AST.hpp"

class FunctionAST;

class FunctionGen : public DemuxComponent, public Generator<FunctionAST>,
                    public Generator<BlockAST>
{
public:
    virtual llvm::Value * emit(VflModule & module, FunctionAST & node) override;

    virtual llvm::Value * emit(VflModule & module, BlockAST & node) override;
};

#endif // VFL_FUNCTIONGEN_HPP
