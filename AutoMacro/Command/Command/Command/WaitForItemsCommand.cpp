#include "AutoMacro/Command/Command/Command/WaitForItemsCommand.h"

#include "AutoMacro/Command/Command/Parameter/WaitForItemsCommandParameter.h"

namespace AutoMacro {
namespace Impl {
WaitForItemsCommand::WaitForItemsCommand(WaitForItemsCommandParameter* p)
    : ExecuteUntilItemsCommand(p),
      kvm(p->kvm),
      delayBetweenRepeatitions(p->delayBetweenRepeatitions) {
}

std::shared_ptr<Command> WaitForItemsCommand::createExecuteCommand() {
    DelayCommandParameter dp(kvm);
    dp.ms = delayBetweenRepeatitions;
    return Factory::createCommand(&dp);
}
}  // namespace Impl
}  // namespace AutoMacro
