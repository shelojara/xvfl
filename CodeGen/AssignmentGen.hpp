#ifndef VFL_ASSIGNMENTGEN_HPP
#define VFL_ASSIGNMENTGEN_HPP


#include "../Demux/DemuxComponent.hpp"
#include "../AST/StatementAST.hpp"

class AssignmentGen : public DemuxComponent, public Generator<AssignmentAST>
{
public:
    virtual llvm::Value * emit(VflModule & module, AssignmentAST & node) override;
};


#endif //VFL_ASSIGNMENTGEN_HPP
