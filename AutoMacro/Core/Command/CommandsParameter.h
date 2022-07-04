#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Core/Kvm/Kvm.h"
#include "AutoMacro/Core/Command/Command.h"

namespace AutoMacro {
class CommandsParameter : public CommandParameter {
 public:
    CommandsParameter(Kvm kvm,
        const std::vector<std::shared_ptr<Command>>& commands)
        : CommandParameter(kvm),
          commands(commands) {}

    const std::vector<std::shared_ptr<Command>>& commands;
};
}  // namespace AutoMacro
