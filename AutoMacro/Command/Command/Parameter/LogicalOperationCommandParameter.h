#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Core/Core.h"

enum class LogicalOperator {
    AND,
    OR,
    XOR,
};

namespace AutoMacro {
class LogicalOperationCommandParameter {
 public:
    LogicalOperationCommandParameter(
        std::vector<std::shared_ptr<TCommand<bool>>> commands,
        LogicalOperator op)
        : commands(commands), op(op) {}

    LogicalOperationCommandParameter(
        std::shared_ptr<TCommand<bool>> command,
        bool value,
        LogicalOperator op)
        : commands({ command }), values({ value }), op(op) {}

    std::vector<std::shared_ptr<TCommand<bool>>> commands;
    std::vector<bool> values;
    LogicalOperator op;
};
}  // namespace AutoMacro
