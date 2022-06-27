#include "AutoMacro/Command/Command.h"

#include <memory>

#include "AutoMacro/Command/Command/DesktopSwitchCommand.h"
#include "AutoMacro/Command/Command/MouseClickCommand.h"
#include "AutoMacro/Command/Command/MouseMoveCommand.h"
#include "AutoMacro/Command/Command/SendKeyCommand.h"
#include "AutoMacro/Command/Command/ShortcutCommand.h"
#include "AutoMacro/Command/Command/WaitForItemCommand.h"
#include "AutoMacro/Command/Command/WaitForItemsCommand.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Command::Command> createCommand(
    Command::DesktopSwitchCommandParameter* parameter) {
    return std::make_shared<Command::Impl::DesktopSwitchCommand>(parameter);
}

std::shared_ptr<Command::Command> createCommand(
    Command::MouseClickCommandParameter* parameter) {
    return std::make_shared<Command::Impl::MouseClickCommand>(parameter);
}

std::shared_ptr<Command::Command> createCommand(
    Command::MouseMoveCommandParameter* parameter) {
    return std::make_shared<Command::Impl::MouseMoveCommand>(parameter);
}

std::shared_ptr<Command::Command> createCommand(
    Command::SendKeyCommandParameter* parameter) {
    return std::make_shared<Command::Impl::SendKeyCommand>(parameter);
}

std::shared_ptr<Command::Command> createCommand(
    Command::ShortcutCommandParameter* parameter) {
    return std::make_shared<Command::Impl::ShortcutCommand>(parameter);
}

std::shared_ptr<Command::Command> createCommand(
    Command::WaitForItemCommandParameter* parameter) {
    return std::make_shared<Command::Impl::WaitForItemCommand>(parameter);
}

std::shared_ptr<Command::Command> createCommand(
    Command::WaitForItemsCommandParameter* parameter) {
    return std::make_shared<Command::Impl::WaitForItemsCommand>(parameter);
}
}  // namespace Factory
}  // namespace AutoMacro
