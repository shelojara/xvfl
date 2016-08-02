#ifndef VFL_BINARYOPGEN_HPP
#define VFL_BINARYOPGEN_HPP


#include <llvm/IR/Value.h>
#include "../AST/ExpressionAST.hpp"

class BinaryOpGen : public Generator<BinaryOpAST>
{
public:
    virtual llvm::Value * emit(VflModule & module, BinaryOpAST & node) override;
};


#endif //VFL_BINARYOPGEN_HPP
