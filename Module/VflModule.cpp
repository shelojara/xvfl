#include "VflModule.hpp"

llvm::Module * VflModule::getLLVMModule() const
{
    return module;
}
