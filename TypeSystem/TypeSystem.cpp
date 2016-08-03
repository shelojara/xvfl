#include "TypeSystem.hpp"

TypeSystem::TypeSystem()
{
    addCoercion(intTy, floatTy, floatTy);

    addCast(intTy, floatTy, llvm::CastInst::SIToFP);
    addCast(intTy, doubleTy, llvm::CastInst::SIToFP);
    addCast(boolTy, doubleTy, llvm::CastInst::SIToFP);
    addCast(floatTy, doubleTy, llvm::CastInst::FPExt);
    addCast(floatTy, intTy, llvm::CastInst::FPToSI);
    addCast(doubleTy, intTy, llvm::CastInst::FPToSI);

    addOp(intTy, "+", llvm::Instruction::Add);
    addOp(floatTy, "+", llvm::Instruction::FAdd);
    addOp(doubleTy, "+", llvm::Instruction::FAdd);

    addOp(intTy, "-", llvm::Instruction::Sub);
    addOp(floatTy, "-", llvm::Instruction::FSub);
    addOp(doubleTy, "-", llvm::Instruction::FSub);

    addOp(intTy, "*", llvm::Instruction::Mul);
    addOp(floatTy, "*", llvm::Instruction::FMul);
    addOp(doubleTy, "*", llvm::Instruction::FMul);

    addOp(intTy, "/", llvm::Instruction::SDiv);
    addOp(floatTy, "/", llvm::Instruction::FDiv);
    addOp(doubleTy, "/", llvm::Instruction::FDiv);

    addOp(intTy, "%", llvm::Instruction::SRem);
    addOp(floatTy, "%", llvm::Instruction::FRem);
    addOp(doubleTy, "%", llvm::Instruction::FRem);
}

void TypeSystem::addCoercion(llvm::Type *l, llvm::Type *r, llvm::Type *result)
{
    if (coerceTab.find(l) == coerceTab.end()) {
        coerceTab[l] = std::map<llvm::Type*, llvm::Type*>();
    }

    coerceTab[l][r] = result;
}

void TypeSystem::addCast(llvm::Type * from, llvm::Type * to, llvm::CastInst::CastOps op)
{
    if (castTab.find(from) == castTab.end()) {
        castTab[from] = std::map<llvm::Type*, llvm::CastInst::CastOps>();
    }

    castTab[from][to] = op;
}

void TypeSystem::addOp(llvm::Type * type, std::string op, llvm::Instruction::BinaryOps llvmOp)
{
    mathOpTab[std::pair<llvm::Type*, std::string>(type, op)] = llvmOp;
}

llvm::CastInst::CastOps TypeSystem::getCastOp(llvm::Type * from, llvm::Type * to)
{
    if (castTab.find(from) == castTab.end()) {
        throw std::runtime_error("Type cannot be casted: " + std::to_string(from->getTypeID()));
    }

    auto subIt = castTab[from].find(to);

    if (subIt != castTab[from].end()) {
        return castTab[from][to];
    }

    throw std::runtime_error("Unknown cast from " + std::to_string(from->getTypeID())
                             + " to " + std::to_string(to->getTypeID()));
}

llvm::Type * TypeSystem::coerce(llvm::Type * l, llvm::Type * r)
{
    if (l == r) {
        return l;
    }

    auto it = coerceTab.find(l);

    if (it != coerceTab.end()) {
        auto it2 = it->second.find(r);

        if (it2 != it->second.end()) {
            return it2->second;
        }
    }

    it = coerceTab.find(r);

    if (it != coerceTab.end()) {
        auto it2 = it->second.find(l);

        if (it2 != it->second.end()) {
            return it2->second;
        }
    }

    throw std::runtime_error("No conversion between " + std::to_string(l->getTypeID())
                             + " and " + std::to_string(r->getTypeID()));
}

llvm::Value * TypeSystem::cast(llvm::Value * value, llvm::Type * type, llvm::BasicBlock * block)
{
    if (value->getType() == type) {
        return value;
    }

    return llvm::CastInst::Create(getCastOp(value->getType(), type), value, type, "cast", block);
}

llvm::Instruction::BinaryOps TypeSystem::getMathOp(llvm::Type *type, std::string op)
{
    return mathOpTab[std::pair<llvm::Type*, std::string>(type, op)];
}

bool TypeSystem::isFP(llvm::Type * type)
{
    return type != intTy;
}

llvm::CmpInst::Predicate TypeSystem::getCmpPredicate(llvm::Type * type, std::string op)
{
    if (type == intTy) {
        if (op == "==") {
            return llvm::CmpInst::Predicate::ICMP_EQ;
        } else if (op == "!=") {
            return llvm::CmpInst::Predicate::ICMP_NE;
        } else if (op == "<") {
            return llvm::CmpInst::Predicate::ICMP_SLT;
        } else if (op == ">") {
            return llvm::CmpInst::Predicate::ICMP_SGT;
        } else if (op == "<=") {
            return llvm::CmpInst::Predicate::ICMP_SLE;
        } else if (op == ">=") {
            return llvm::CmpInst::Predicate::ICMP_SGE;
        }
    } else {
        if (op == "==") {
            return llvm::CmpInst::Predicate::FCMP_OEQ;
        } else if (op == "!=") {
            return llvm::CmpInst::Predicate::FCMP_ONE;
        } else if (op == "<") {
            return llvm::CmpInst::Predicate::FCMP_OLT;
        } else if (op == ">") {
            return llvm::CmpInst::Predicate::FCMP_OGT;
        } else if (op == "<=") {
            return llvm::CmpInst::Predicate::FCMP_OLE;
        } else if (op == ">=") {
            return llvm::CmpInst::Predicate::FCMP_OGE;
        }
    }

    throw std::runtime_error("Not a comparison operator: " + op);
}

void TypeSystem::addStructType(std::string name, llvm::StructType * type)
{
    if (structTypes.find(name) != structTypes.end()) {
        throw std::runtime_error("Struct type already defined: " + name);
    }

    structTypes[name] = std::pair<llvm::StructType*, std::vector<std::string>>(type,
            std::vector<std::string>());
}

llvm::StructType * TypeSystem::getStructType(std::string name)
{
    if (structTypes.find(name) == structTypes.end()) {
        throw std::runtime_error("Struct type not defined: " + name);
    }

    return structTypes[name].first;
}

int TypeSystem::getStructMemberIndex(std::string structName, std::string member)
{
    auto it = structTypes.find(structName);

    if (it == structTypes.end()) {
        throw std::runtime_error("Unknown struct: " + structName);
    }

    std::vector<std::string> members = it->second.second;

    for (int i = 0; i < members.size(); ++i) {
        if (members[i] == member) {
            return i;
        }
    }

    throw std::runtime_error("Unknown member: " + member + " for struct: " + structName);
}

void TypeSystem::setStructMembers(std::string name, std::vector<std::string> members)
{
    auto it = structTypes.find(name);

    if (it != structTypes.end()) {
        it->second.second = members;
    }
}