#include "AutoMacro/Command/Command/Factory/DesktopSwitchCommandFactory.h"

#include <memory>

#include "AutoMacro/Command/Command/Parameter/DesktopSwitchCommandParameter.h"
#include "AutoMacro/Command/Command/Command/DesktopSwitchCommand.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Command> createCommand(
        DesktopSwitchCommandParameter* p) {
    auto command = createTCommand(p);
    return createCommand(command);
}

std::shared_ptr<TCommand<void>> createTCommand(
        DesktopSwitchCommandParameter* p) {
    return std::make_shared<Impl::DesktopSwitchCommand>(p);
}
}  // namespace Factory
}  // namespace AutoMacro
