#ifndef VFL_TYPE_HPP
#define VFL_TYPE_HPP

#include <string>
#include <memory>
#include <llvm/IR/Type.h>

#include "../AST/ExpressionAST.hpp"
#include "TypeSystem.hpp"

class Type
{
protected:
    std::string name;

public:
    Type(std::string name) :
            name(name)
    {}

    virtual ~Type() = default;

    /**
     * Returns a LLVM Type from a string representation given by the parser.
     *
     * @param typeSystem the current type system
     * @return the LLVM Type
     */
    virtual llvm::Type * getType(TypeSystem & typeSystem);

    virtual bool isArray()
    {
        return false;
    }

    virtual bool isStruct()
    {
        return false;
    }
};


class ArrayType : public Type
{
    std::shared_ptr<ExpressionAST> size;

public:
    ArrayType(std::string name, std::shared_ptr<ExpressionAST> size = std::make_shared<IntegerAST>(1)) :
            Type(name), size(size)
    {}

    virtual llvm::Type * getType(TypeSystem & typeSys);

    virtual bool isArray()
    {
        return true;
    }
};


class StructType : public Type
{
public:
    StructType(std::string name) :
            Type(name)
    {}

    virtual llvm::Type * getType(TypeSystem & typeSys);

    virtual bool isStruct()
    {
        return true;
    }
};


#endif //VFL_TYPE_HPP
