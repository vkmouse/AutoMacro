#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Core/Command/Command.h"
#include "AutoMacro/Core/Command/CommandsParameter.h"
#include "AutoMacro/Core/Kvm/Kvm.h"

namespace AutoMacro {
namespace Impl {
class Commands : public Command {
 public:
    explicit Commands(CommandsParameter* p);

 protected:
     virtual void executeCommand();

 private:
    const std::vector<std::shared_ptr<Command>>& commands_;
};
}  // namespace Impl
}  // namespace AutoMacro
