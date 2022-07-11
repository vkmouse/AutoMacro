#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Core/Core.h"

enum class ArithmeticOperator {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
};

namespace AutoMacro {
class ArithmeticOperationCommandParameter {
 public:
    ArithmeticOperationCommandParameter(
        int* lhs, int rhs, ArithmeticOperator op)
        : lhs(lhs), rhs(rhs), op(op) {}

    int* lhs;
    int rhs;
    ArithmeticOperator op;
};
}  // namespace AutoMacro
