#pragma once
#include <memory>

#include "AutoMacro/Core/Command/Command.h"

namespace AutoMacro {
class WhileCommandParameter {
 public:
    WhileCommandParameter() {}

    WhileCommandParameter(std::shared_ptr<Command> executeCommand,
        std::shared_ptr<TCommand<bool>> requestCommand)
        : executeCommand(executeCommand), requestCommand(requestCommand) {}

    std::shared_ptr<Command> executeCommand = nullptr;
    std::shared_ptr<TCommand<bool>> requestCommand = nullptr;
};
}  // namespace AutoMacro
