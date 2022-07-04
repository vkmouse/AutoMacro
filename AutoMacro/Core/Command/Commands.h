#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Core/Command/Command.h"
#include "AutoMacro/Core/Command/CommandsParameter.h"

namespace AutoMacro {
namespace Impl {
class Commands : public Command {
 public:
    explicit Commands(CommandsParameter* p);

    void execute() final;

 private:
    std::vector<std::shared_ptr<Command>> commands_;
};
}  // namespace Impl
}  // namespace AutoMacro
