#include "AutoMacro/Command/Command.h"

#include <memory>

#include "AutoMacro/Command/Command/SendKeyCommand.h"
#include "AutoMacro/Command/Command/WaitForItemCommand.h"
#include "AutoMacro/Command/Command/WaitForItemsCommand.h"
#include "AutoMacro/Command/Command/ShortcutCommand.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Command::Command> createCommand(
    Command::SendKeyCommandParameter* parameter) {
    return std::make_shared<Command::Impl::SendKeyCommand>(parameter);
}

std::shared_ptr<Command::Command> createCommand(
    Command::WaitForItemCommandParameter* parameter) {
    return std::make_shared<Command::Impl::WaitForItemCommand>(parameter);
}

std::shared_ptr<Command::Command> createCommand(
    Command::WaitForItemsCommandParameter* parameter) {
    return std::make_shared<Command::Impl::WaitForItemsCommand>(parameter);
}

std::shared_ptr<Command::Command> createCommand(
    Command::ShortcutCommandParameter* parameter) {
    return std::make_shared<Command::Impl::ShortcutCommand>(parameter);
}
}  // namespace Factory
}  // namespace AutoMacro
