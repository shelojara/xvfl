#ifndef VFL_BASICVALUEGEN_HPP
#define VFL_BASICVALUEGEN_HPP


#include "Generator.hpp"
#include "../AST/ExpressionAST.hpp"
#include "../Demux/DemuxComponent.hpp"

class BasicValueGen : public DemuxComponent, public Generator<IntegerAST>,
                      public Generator<FloatAST>,
                      public Generator<BoolAST>
{
public:
    virtual llvm::Value * emit(VflModule & module, IntegerAST & node) override;

    virtual llvm::Value * emit(VflModule & module, BoolAST & node) override;

    virtual llvm::Value * emit(VflModule & module, FloatAST & node) override;
};


#endif //VFL_BASICVALUEGEN_HPP
