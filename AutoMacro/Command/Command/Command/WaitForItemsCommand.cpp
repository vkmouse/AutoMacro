#include "AutoMacro/Command/Command/Command/WaitForItemsCommand.h"

#include "AutoMacro/Command/Command/Parameter/WaitForItemsCommandParameter.h"

namespace AutoMacro {
namespace Impl {
WaitForItemsCommand::WaitForItemsCommand(WaitForItemsCommandParameter* p)
    : ExecuteUntilItemsCommand(p) {
    DelayCommandParameter dp(p->kvm);
    dp.ms = p->delayBetweenRepeatitions;
    setExecuteCommand(Factory::createCommand(&dp));
}
}  // namespace Impl
}  // namespace AutoMacro
