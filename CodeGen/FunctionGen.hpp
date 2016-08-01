#ifndef VFL_FUNCTIONGEN_HPP
#define VFL_FUNCTIONGEN_HPP

#include <llvm/IR/Value.h>

#include "Generator.hpp"

class FunctionAST;

class FunctionGen : public Generator<FunctionAST>
{
public:
    virtual llvm::Value * emit(VflModule & module, FunctionAST & node) override;
};

#endif // VFL_FUNCTIONGEN_HPP
