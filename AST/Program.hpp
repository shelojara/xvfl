#ifndef VFL_PROGRAM_HPP
#define VFL_PROGRAM_HPP

#include <vector>
#include <memory>

#include "../Util/NonCopyable.hpp"
#include "FunctionAST.hpp"
#include "StructAST.hpp"

typedef std::vector<std::shared_ptr<FunctionAST>> FunctionList;
typedef std::vector<std::shared_ptr<StructAST>> StructList;

/**
 * The program class is a storage of top level instructions.
 */
class Program : private NonCopyable
{
private:
    FunctionList functionList;
    StructList structList;

public:
    /**
     * @param function the function ast node.
     */
    void addFunction(FunctionAST * function)
    {
        functionList.push_back(std::shared_ptr<FunctionAST>(function));
    }

    void addStruct(StructAST * structDef)
    {
        structList.push_back(std::shared_ptr<StructAST>(structDef));
    }

    const FunctionList & getFunctionList() const
    {
        return functionList;
    }
};


#endif //VFL_PROGRAM_HPP
