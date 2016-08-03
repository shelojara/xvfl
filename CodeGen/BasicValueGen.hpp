#ifndef VFL_BASICVALUEGEN_HPP
#define VFL_BASICVALUEGEN_HPP


#include "Generator.hpp"
#include "../AST/ExpressionAST.hpp"
#include "../Demux/DemuxComponent.hpp"
#include "../AST/StatementAST.hpp"

class BasicValueGen : public DemuxComponent, public Generator<IntegerAST>,
                      public Generator<FloatAST>,
                      public Generator<BoolAST>, public Generator<ExpressionStatementAST>
{
public:
    virtual llvm::Value * emit(VflModule & module, IntegerAST & node) override;

    virtual llvm::Value * emit(VflModule & module, BoolAST & node) override;

    virtual llvm::Value * emit(VflModule & module, FloatAST & node) override;

    virtual llvm::Value * emit(VflModule & module, ExpressionStatementAST & node) override;
};


#endif //VFL_BASICVALUEGEN_HPP
