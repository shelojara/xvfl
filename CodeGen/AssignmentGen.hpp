#ifndef VFL_ASSIGNMENTGEN_HPP
#define VFL_ASSIGNMENTGEN_HPP


#include "../Demux/DemuxComponent.hpp"
#include "../AST/StatementAST.hpp"

class AssignmentGen : public DemuxComponent, public Generator<AssignmentAST>
{
public:
    /**
     * Generates the code for an AssignmentAST, it needs a lvalue and a rvalue,
     * the lvalue should be a GEP value, the the rvalue can be any value that
     * has the same type of the underlying value of the GEP.
     */
    virtual llvm::Value * emit(VflModule & module, AssignmentAST & node) override;
};


#endif //VFL_ASSIGNMENTGEN_HPP
