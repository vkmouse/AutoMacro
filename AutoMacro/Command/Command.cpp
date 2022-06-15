#pragma once
#include "AutoMacro/Command/Command.h"

#include <Windows.h>

namespace AutoMacro {
namespace Command {
Command::Command() : delayBeforeCommand(0), delayAfterCommand(0) {
}

void Command::execute() {
    Sleep(delayBeforeCommand);
    executeCommand();
    Sleep(delayAfterCommand);
}
}  // namespace Command
}  // namespace AutoMacro
