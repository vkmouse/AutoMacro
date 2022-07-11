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

    std::vector<std::shared_ptr<TCommand<bool>>> commands;
    LogicalOperator op;
};
}  // namespace AutoMacro
