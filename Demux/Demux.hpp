#ifndef VFL_DEMUX_HPP
#define VFL_DEMUX_HPP

#include <llvm/IR/Value.h>

#include "../AST/FunctionAST.hpp"
#include "../AST/Program.hpp"

#include "../Module/VflModule.hpp"
#include "../CodeGen/FunctionGen.hpp"
#include "../Util/NonCopyable.hpp"
#include "../CodeGen/BinaryOpGen.hpp"
#include "../CodeGen/FunctionCallGen.hpp"
#include "../CodeGen/StringGen.hpp"
#include "../CodeGen/IdentifierGen.hpp"
#include "../CodeGen/BasicValueGen.hpp"
#include "../CodeGen/ArrayGen.hpp"
#include "../CodeGen/StructGen.hpp"
#include "../CodeGen/AssignmentGen.hpp"
#include "../CodeGen/VarDeclGen.hpp"
#include "../CodeGen/ForGen.hpp"
#include "../CodeGen/BuiltInFuncGen.hpp"

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

    BinaryOpGen binaryOpGen;

    FunctionCallGen functionCallGen;

    StringGen stringGen;

    IdentifierGen identifierGen;

    BasicValueGen basicValueGen;

    ArrayGen arrayGen;

    StructGen structGen;

    AssignmentGen assignmentGen;

    VarDeclGen varDeclGen;

    ForGen forGen;

    BuiltInFuncGen builtInFuncGen;

public:
    Demux(VflModule & module) :
            module(module)
    {
        functionGen.setDemux(this);
        binaryOpGen.setDemux(this);
        functionCallGen.setDemux(this);
        stringGen.setDemux(this);
        identifierGen.setDemux(this);
        basicValueGen.setDemux(this);
        arrayGen.setDemux(this);
        structGen.setDemux(this);
        assignmentGen.setDemux(this);
        varDeclGen.setDemux(this);
        forGen.setDemux(this);
        builtInFuncGen.setDemux(this);
    }

    void walkAST(Program & program);

    llvm::Value * visit(FunctionAST & node);

    llvm::Value * visit(BlockAST & node);

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

    llvm::Value * visit(ForAST & node);

    llvm::Value * visit(VarDeclAST & node);

    llvm::Value * visit(ExpressionStatementAST & node);

    llvm::Value * visit(AssignmentAST & node);

    llvm::Value * visit(ReturnAST & node);

    llvm::Value * visit(IfAST & node);

    llvm::Value * visit(PrintAST & node);

    llvm::Value * visit(ParameterAST & node);

    llvm::Value * visit(StructAST & node);
};


#endif // VFL_DEMUX_HPP
