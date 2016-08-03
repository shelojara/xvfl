#ifndef VFL_TYPESYSTEM_HPP
#define VFL_TYPESYSTEM_HPP

#include <memory>
#include <map>

#include <llvm/IR/Type.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Instruction.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/InstrTypes.h>

#include "../Util/NonCopyable.hpp"


class TypeSystem : private NonCopyable
{
private:
    std::map<llvm::Type*, std::map<llvm::Type*, llvm::Type*>> coerceTab;

    std::map<llvm::Type*, std::map<llvm::Type*, llvm::CastInst::CastOps>> castTab;

    std::map<std::pair<llvm::Type*, std::string>, llvm::Instruction::BinaryOps> mathOpTab;

    std::map<std::string, std::pair<llvm::StructType*, std::vector<std::string>>> structTypes;

    void addCoercion(llvm::Type *l, llvm::Type *r, llvm::Type *result);

    void addCast(llvm::Type * from, llvm::Type * to, llvm::CastInst::CastOps op);

    void addOp(llvm::Type * type, std::string op, llvm::Instruction::BinaryOps llvmOp);

    llvm::CastInst::CastOps getCastOp(llvm::Type * from, llvm::Type * to);

public:
    llvm::Type * floatTy = llvm::Type::getFloatTy(llvm::getGlobalContext());
    llvm::Type * intTy = llvm::Type::getInt32Ty(llvm::getGlobalContext());
    llvm::Type * charTy = llvm::Type::getInt8Ty(llvm::getGlobalContext());
    llvm::Type * doubleTy = llvm::Type::getDoubleTy(llvm::getGlobalContext());
    llvm::Type * boolTy = llvm::Type::getInt1Ty(llvm::getGlobalContext());
    llvm::Type * stringTy = llvm::Type::getInt8PtrTy(llvm::getGlobalContext());
    llvm::Type * voidTy = llvm::Type::getVoidTy(llvm::getGlobalContext());

    TypeSystem();

    /**
     * Takes two types and returns a type that they both can cast to.
     *
     * Example usage:
     * <pre>
     * coerce(floatTy, intTy); # -> floatTy
     * </pre>
     *
     * @return the coercion type.
     */
    llvm::Type * coerce(llvm::Type * l, llvm::Type * r);

    /**
     * Casts one value to a given type.
     *
     * This method will throw an exception in case the type cannot be casted.
     *
     * @return the casted value, or the value given if it already has the required type.
     */
    llvm::Value * cast(llvm::Value * value, llvm::Type * type, llvm::BasicBlock * block);

    /**
     * Returns the math operation for the given type and op.
     *
     * @param op    one of: +, -, /, *, %
     *
     * @return the LLVM math operator.
     */
    llvm::Instruction::BinaryOps getMathOp(llvm::Type * type, std::string op);

    /**
     * @return true if the type is a floating point.
     */
    bool isFP(llvm::Type * type);

    llvm::CmpInst::Predicate getCmpPredicate(llvm::Type * type, std::string op);

    void addStructType(std::string name, llvm::StructType * type);

    void setStructMembers(std::string name, std::vector<std::string> members);

    llvm::StructType * getStructType(std::string name);

    int getStructMemberIndex(std::string structName, std::string member);
};


#endif //VFL_TYPESYSTEM_HPP
