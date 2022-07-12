#include "AutoMacro/Command/Command/Command/LogicalOperationCommand.h"

#include <functional>

#include "AutoMacro/Command/Command/Parameter/LogicalOperationCommandParameter.h"

namespace AutoMacro {
namespace Impl {
LogicalOperationCommand::LogicalOperationCommand(
    LogicalOperationCommandParameter* p)
    : commands(p->commands), values(p->values), op(p->op) {
}

bool LogicalOperationCommand::execute() {
    std::function<bool(bool, bool)> logicalFunction;
    switch (op) {
    case LogicalOperator::AND:
        logicalFunction = [](bool lhs, bool rhs) { return lhs && rhs; };
        break;
    case LogicalOperator::OR:
        logicalFunction = [](bool lhs, bool rhs) { return lhs || rhs; };
        break;
    case LogicalOperator::XOR:
        logicalFunction = [](bool lhs, bool rhs) { return lhs ^ rhs; };
        break;
    }

    bool output = commands.front()->execute();
    for (int i = 1; i < commands.size(); i++) {
        output = logicalFunction(output, commands[i]->execute());
    }
    for (bool value : values) {
        output = logicalFunction(output, value);
    }

    return output;
}
}  // namespace Impl
}  // namespace AutoMacro
