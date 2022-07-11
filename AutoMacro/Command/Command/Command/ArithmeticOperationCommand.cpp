#include "AutoMacro/Command/Command/Command/ArithmeticOperationCommand.h"

#include <functional>

#include "AutoMacro/Command/Command/Parameter/ArithmeticOperationCommandParameter.h"

namespace AutoMacro {
namespace Impl {
ArithmeticOperationCommand::ArithmeticOperationCommand(
    ArithmeticOperationCommandParameter* p)
    : lhs(p->lhs), rhs(p->rhs), op(p->op) {
}

void ArithmeticOperationCommand::execute() {
    std::function<int(int, int)> arithmeticFunction;
    switch (op) {
    case ArithmeticOperator::ADD:
        arithmeticFunction = [](int lhs, int rhs) { return lhs + rhs; };
        break;
    case ArithmeticOperator::SUBTRACT:
        arithmeticFunction = [](int lhs, int rhs) { return lhs - rhs; };
        break;
    case ArithmeticOperator::MULTIPLY:
        arithmeticFunction = [](int lhs, int rhs) { return lhs * rhs; };
        break;
    case ArithmeticOperator::DIVIDE:
        arithmeticFunction = [](int lhs, int rhs) { return lhs / rhs; };
        break;
    }

    *lhs = arithmeticFunction(*lhs, rhs);
}
}  // namespace Impl
}  // namespace AutoMacro
