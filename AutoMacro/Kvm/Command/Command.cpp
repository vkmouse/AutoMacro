#include "AutoMacro/Kvm/Command/Command.h"

#include <memory>

#include "AutoMacro/Kvm/Command/DesktopSwitchCommand.h"
#include "AutoMacro/Kvm/Command/DesktopSwitchCommandParameter.h"
#include "AutoMacro/Kvm/Command/MouseClickCommand.h"
#include "AutoMacro/Kvm/Command/MouseClickCommandParameter.h"
#include "AutoMacro/Kvm/Command/SendKeyCommand.h"
#include "AutoMacro/Kvm/Command/SendKeyCommandParameter.h"
#include "AutoMacro/Kvm/Command/ShortCutCommand.h"
#include "AutoMacro/Kvm/Command/ShortCutCommandParameter.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Command> createCommand(
        DesktopSwitchCommandParameter* parameter) {
    return createCommand(createTCommand(parameter));
}

std::shared_ptr<Command> createCommand(
    SendKeyCommandParameter* parameter) {
    return createCommand(createTCommand(parameter));
}

std::shared_ptr<Command> createCommand(
    ShortcutCommandParameter* parameter) {
    return createCommand(createTCommand(parameter));
}

std::shared_ptr<Command> createCommand(
    MouseClickCommandParameter* parameter) {
    return createCommand(createTCommand(parameter));
}

std::shared_ptr<TCommand<void>> createTCommand(
    DesktopSwitchCommandParameter* parameter) {
    return std::make_shared<Impl::DesktopSwitchCommand>(parameter);
}

std::shared_ptr<TCommand<void>> createTCommand(
    SendKeyCommandParameter* parameter) {
    return std::make_shared<Impl::SendKeyCommand>(parameter);
}

std::shared_ptr<TCommand<void>> createTCommand(
    ShortcutCommandParameter* parameter) {
    return std::make_shared<Impl::ShortcutCommand>(parameter);
}

std::shared_ptr<TCommand<void>> createTCommand(
    MouseClickCommandParameter* parameter) {
    return std::make_shared<Impl::MouseClickCommand>(parameter);
}
}  // namespace Factory
}  // namespace AutoMacro
