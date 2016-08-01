#ifndef VFL_PROGRAM_HPP
#define VFL_PROGRAM_HPP

#include <vector>
#include <memory>

#include "FunctionAST.hpp"
#include "../Util/NonCopyable.hpp"

typedef std::vector<std::shared_ptr<FunctionAST>> FunctionList;

/**
 * The program class is a storage of top level instructions.
 */
class Program : private NonCopyable
{
private:
    FunctionList functionList;

public:
    /**
     * @param function the function ast node.
     */
    void addFunction(FunctionAST * function)
    {
        functionList.push_back(std::shared_ptr<FunctionAST>(function));
    }

    const FunctionList & getFunctionList() const
    {
        return functionList;
    }
};


#endif //VFL_PROGRAM_HPP
