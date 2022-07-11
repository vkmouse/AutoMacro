#pragma once
enum class ComparisonOperator {
    EQUAL,
    GREATER_THAN,
    GREATER_THAN_OR_EQUAL,
    LESS_THAN,
    LESS_THAN_OR_EQUAL,
    NOT_EQUAL
};

namespace AutoMacro {
class ComparisonOperationCommandParameter {
 public:
    ComparisonOperationCommandParameter(
        const int& lhs, int rhs, ComparisonOperator op)
        : lhs(lhs), rhs(rhs), op(op) {}

    const int& lhs;
    int rhs;
    ComparisonOperator op;
};
}  // namespace AutoMacro
