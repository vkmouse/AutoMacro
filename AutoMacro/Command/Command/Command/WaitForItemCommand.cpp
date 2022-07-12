#include "AutoMacro/Command/Command/Command/WaitForItemCommand.h"

#include "AutoMacro/Command/Command/Parameter/WaitForItemCommandParameter.h"

namespace AutoMacro {
namespace Impl {
WaitForItemCommand::WaitForItemCommand(WaitForItemCommandParameter* p)
    : ExecuteUntilItemCommand(p) {
    DelayCommandParameter dp(p->kvm);
    dp.ms = p->delayBetweenRepeatitions;
    setExecuteCommand(Factory::createCommand(&dp));
}
}  // namespace Impl
}  // namespace AutoMacro
