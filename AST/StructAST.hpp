#ifndef VFL_STRUCTAST_HPP
#define VFL_STRUCTAST_HPP


#include <string>
#include <vector>

#include "NodeAST.hpp"

class ParameterAST;

typedef std::vector<std::shared_ptr<ParameterAST>> ParameterList;

class Demux;

class StructAST : public NodeAST
{
    std::string name;
    ParameterList members;

public:
    StructAST(std::string name, ParameterList members) :
            name(name), members(members)
    {}

    virtual ~StructAST() = default;

    virtual llvm::Value * accept(Demux * demux) override;

    std::string getName()
    {
        return name;
    }

    ParameterList & getMembers()
    {
        return members;
    }
};


#endif //VFL_STRUCTAST_HPP
