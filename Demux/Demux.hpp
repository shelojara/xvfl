#ifndef VFL_DEMUX_HPP
#define VFL_DEMUX_HPP

#include <llvm/IR/Value.h>

#include "../AST/AST.hpp"
#include "../AST/FunctionAST.hpp"
#include "../AST/Program.hpp"

#include "../Module/VflModule.hpp"
#include "../CodeGen/FunctionGen.hpp"
#include "../Util/NonCopyable.hpp"

class FunctionAST;
class Program;

/**
 * The demux class serves as a dispatcher of generators,
 * and retrieves a single response from each one of them.
 */
class Demux : private NonCopyable
{
private:
    VflModule & module;

    FunctionGen functionGen;

public:
    Demux(VflModule & module) : module(module) {}

    void walkAST(Program * program);

    llvm::Value * visit(FunctionAST & node);

    llvm::Value * visit(BinaryOpAST & node);

    llvm::Value * visit(FunctionCallAST & node);

    llvm::Value * visit(VersionInvAST & node);

    llvm::Value * visit(StringAST & node);

    llvm::Value * visit(IdentifierAST & node);

    llvm::Value * visit(IntegerAST & node);

    llvm::Value * visit(BoolAST & node);

    llvm::Value * visit(FloatAST & node);

    llvm::Value * visit(ArrayAST & node);

    llvm::Value * visit(ArrayIndexAST & node);

    llvm::Value * visit(StructMemberAST & node);
};


#endif /* VFL_DEMUX_HPP */
