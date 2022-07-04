#pragma once
#include <memory>
#include <vector>

namespace AutoMacro {
class CommandsParameter {
 public:
    explicit CommandsParameter(
        std::vector<std::shared_ptr<Command>> commands)
        : commands(commands) {}

    std::vector<std::shared_ptr<Command>> commands;
};
}  // namespace AutoMacro
