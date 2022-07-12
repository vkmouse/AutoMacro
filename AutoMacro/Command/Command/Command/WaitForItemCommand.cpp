#include "AutoMacro/Command/Command/Command/WaitForItemCommand.h"

#include "AutoMacro/Command/Command/Parameter/WaitForItemCommandParameter.h"

namespace AutoMacro {
namespace Impl {
WaitForItemCommand::WaitForItemCommand(WaitForItemCommandParameter* p)
    : ExecuteUntilItemCommand(p),
      kvm(p->kvm),
      delayBetweenRepeatitions(p->delayBetweenRepeatitions) {
}

std::shared_ptr<Command> WaitForItemCommand::createExecuteCommand() {
    DelayCommandParameter dp(kvm);
    dp.ms = delayBetweenRepeatitions;
    return Factory::createCommand(&dp);
}
}  // namespace Impl
}  // namespace AutoMacro
