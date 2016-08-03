#ifndef VFL_FUNCTIONGEN_HPP
#define VFL_FUNCTIONGEN_HPP

#include <llvm/IR/Value.h>

#include "Generator.hpp"
#include "../Demux/DemuxComponent.hpp"
#include "../AST/FunctionAST.hpp"

class FunctionAST;

class FunctionGen : public DemuxComponent, public Generator<FunctionAST>,
                    public Generator<BlockAST>, public Generator<ParameterAST>
{
public:
    virtual llvm::Value * emit(VflModule & module, FunctionAST & node) override;

    virtual llvm::Value * emit(VflModule & module, BlockAST & node) override;

    virtual llvm::Value * emit(VflModule & module, ParameterAST & node) override;

    void loadParameters(VflModule & module, llvm::iterator_range<llvm::Function::arg_iterator> args,
            ParameterList parameters);
};

#endif // VFL_FUNCTIONGEN_HPP
