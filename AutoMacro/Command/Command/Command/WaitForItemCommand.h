#pragma once
#include <memory>

#include "AutoMacro/Command/Command/Command/ExecuteUntilItemCommand.h"
#include "AutoMacro/Command/Command/Parameter/WaitForItemCommandParameter.h"
#include "AutoMacro/Command/Command/Parameter/DelayCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class WaitForItemCommand : public ExecuteUntilItemCommand {
 public:
    explicit WaitForItemCommand(WaitForItemCommandParameter* p);

 protected:
     virtual std::shared_ptr<Command> createExecuteCommand();

 private:
    Kvm kvm;
    int delayBetweenRepeatitions;
};
}  // namespace Impl
}  // namespace AutoMacro
