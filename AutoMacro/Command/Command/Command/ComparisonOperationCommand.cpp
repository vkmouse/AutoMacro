#include "AutoMacro/Command/Command/Command/ComparisonOperationCommand.h"

#include "AutoMacro/Command/Command/Parameter/ComparisonOperationCommandParameter.h"

namespace AutoMacro {
namespace Impl {
ComparisonOperationCommand::ComparisonOperationCommand(
    ComparisonOperationCommandParameter* p)
    : lhs(p->lhs), rhs(p->rhs), op(p->op) {
}

bool ComparisonOperationCommand::execute() {
    switch (op) {
    case ComparisonOperator::EQUAL:
        return lhs == rhs;
    case ComparisonOperator::GREATER_THAN:
        return lhs > rhs;
    case ComparisonOperator::GREATER_THAN_OR_EQUAL:
        return lhs >= rhs;
    case ComparisonOperator::LESS_THAN:
        return lhs < rhs;
    case ComparisonOperator::LESS_THAN_OR_EQUAL:
        return lhs <= rhs;
    case ComparisonOperator::NOT_EQUAL:
        return lhs != rhs;
    default:
        return false;
    }
}
}  // namespace Impl
}  // namespace AutoMacro
