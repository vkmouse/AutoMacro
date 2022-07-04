#pragma once
#include <memory>
#include <vector>

namespace AutoMacro {
class CommandsParameter {
 public:
    explicit CommandsParameter(
        const std::vector<std::shared_ptr<Command>>& commands)
        : commands(commands) {}

    const std::vector<std::shared_ptr<Command>>& commands;
};
}  // namespace AutoMacro
