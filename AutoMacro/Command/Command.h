#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Command.h"
#include "AutoMacro/Command/Command/CommandParameter.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Command::Command> createCommand(
    Command::DesktopSwitchCommandParameter* parameter);
DLL_EXPORTS std::shared_ptr<Command::Command> createCommand(
    Command::MouseClickCommandParameter* parameter);
DLL_EXPORTS std::shared_ptr<Command::Command> createCommand(
    Command::MouseMoveCommandParameter* parameter);
DLL_EXPORTS std::shared_ptr<Command::Command> createCommand(
    Command::SendKeyCommandParameter* parameter);
DLL_EXPORTS std::shared_ptr<Command::Command> createCommand(
    Command::ShortcutCommandParameter* parameter);
DLL_EXPORTS std::shared_ptr<Command::Command> createCommand(
    Command::WaitForItemCommandParameter* parameter);
DLL_EXPORTS std::shared_ptr<Command::Command> createCommand(
    Command::WaitForItemsCommandParameter* parameter);
}  // namespace Factory
}  // namespace AutoMacro
