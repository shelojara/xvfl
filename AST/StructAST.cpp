#include "StructAST.hpp"

#include "../Demux/Demux.hpp"

llvm::Value * StructAST::accept(Demux * demux)
{
    return demux->visit(*this);
}
