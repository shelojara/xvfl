#ifndef VFL_STRINGGEN_HPP
#define VFL_STRINGGEN_HPP


#include "../AST/ExpressionAST.hpp"

class StringGen : public Generator<StringAST>
{
public:
    virtual llvm::Value * emit(VflModule & module, StringAST & node) override;
};


#endif //VFL_STRINGGEN_HPP
