#ifndef VFL_NODEAST_HPP
#define VFL_NODEAST_HPP


#include <llvm/IR/Value.h>
#include "../Util/NonCopyable.hpp"

class Demux;

class NodeAST : private NonCopyable
{
public:
    virtual llvm::Value * accept(Demux * demux) = 0;

    virtual ~NodeAST() = default;
};


#endif //VFL_NODEAST_HPP
