#include "BinaryOpGen.hpp"

llvm::Value * BinaryOpGen::emit(VflModule & module, BinaryOpAST & node)
{
    auto left = module.loadIfPtr(demux, node.getLeft());
    auto right = module.loadIfPtr(demux, node.getRight());

    // get the type coercion.
    auto coercion = module.getTypeSystem().coerce(left->getType(), right->getType());

    auto block = module.getBuilder().GetInsertBlock();

    // cast the two values to the coerce type (note: if one of them is already of that type,
    // then no cast is made).
    auto leftCast = module.getTypeSystem().cast(left, coercion, block);
    auto rightCast = module.getTypeSystem().cast(right, coercion, block);

    auto op = node.getOp();

    // check if this is a math of a comparison operator.
    if (op == "+" || op == "-" || op == "/" || op == "*" || op == "%") {
        return llvm::BinaryOperator::Create(module.getTypeSystem().getMathOp(coercion, op),
                leftCast, rightCast, "", block);
    } else {
        // select correct builder function depending of this is a float point
        // type or an integer.
        if (module.getTypeSystem().isFP(coercion)) {
            return module.getBuilder().CreateFCmp(
                    module.getTypeSystem().getCmpPredicate(coercion, op), leftCast, rightCast);
        } else {
            return module.getBuilder().CreateICmp(
                    module.getTypeSystem().getCmpPredicate(coercion, op), leftCast, rightCast);
        }
    }
}
