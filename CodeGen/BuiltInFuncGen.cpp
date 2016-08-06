#include "BuiltInFuncGen.hpp"

llvm::Value * BuiltInFuncGen::emit(VflModule & module, PrintAST & node)
{
    // take the value we want to print.
    auto value = node.getExpression()->accept(demux);

    auto print = module.getLLVMModule()->getOrInsertFunction("printf",
            llvm::FunctionType::get(llvm::IntegerType::getInt32Ty(llvm::getGlobalContext()),
                    llvm::PointerType::get(llvm::Type::getInt8Ty(llvm::getGlobalContext()), 0),
                    true)
    );

    // create the format type accordingly.
    std::string fType;

    if (value->getType()->isIntegerTy()) {
        fType = "%d";
    } else if (value->getType()->isFloatingPointTy()) {
        fType = "%g";
    } else if (value->getType()->isPointerTy()) {
        fType = "%s";
    }

    auto format = StringAST(fType + "\n").accept(demux);

    // if this is a floating pointer, make sure it's a double, since printf needs doubles.
    if (value->getType()->isFloatingPointTy()) {
        value = module.getTypeSystem().cast(value, module.getTypeSystem().doubleTy,
                module.getBuilder().GetInsertBlock());
    }

    return module.getBuilder().CreateCall(print, { format, value });
}
