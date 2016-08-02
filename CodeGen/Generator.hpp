#ifndef VFL_GENERATOR_HPP
#define VFL_GENERATOR_HPP

#include <llvm/IR/Value.h>
#include "../Module/VflModule.hpp"


template <typename T>
class Generator : private NonCopyable
{
public:
    virtual llvm::Value * emit(VflModule & module, T & node) = 0;
};


#endif //VFL_GENERATOR_HPP
