#ifndef VFL_SCOPE_HPP
#define VFL_SCOPE_HPP


#include <string>
#include <map>
#include <llvm/IR/Value.h>
#include "../Util/NonCopyable.hpp"


class Scope : private NonCopyable
{
private:
    std::map<std::string, llvm::Value*> table;

    Scope * parent;

public:
    Scope(Scope * parent) : parent(parent) {}

    void add(std::string name, llvm::Value * value)
    {
        if (table.find(name) != table.end()) {
            throw std::runtime_error("Symbol already declared: " + name);
        }

        table[name] = value;
    }

    llvm::Value * get(std::string name)
    {
        auto it = table.find(name);

        if (it != table.end()) {
            return it->second;
        }

        if (parent != nullptr) {
            return parent->get(name);
        } else {
            return nullptr;
        }
    }
};


#endif //VFL_SCOPE_HPP
