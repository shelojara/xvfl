#ifndef VFL_VFLMODULE_HPP
#define VFL_VFLMODULE_HPP

#include <llvm/IR/Module.h>
#include "../Util/NonCopyable.hpp"


class VflModule : private NonCopyable
{
private:
    llvm::Module * module;

public:
    llvm::Module * getLLVMModule() const;
};


#endif //VFL_VFLMODULE_HPP
