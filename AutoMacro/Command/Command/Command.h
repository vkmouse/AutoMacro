#pragma once
#include <Windows.h>

#include "AutoMacro/Command/Command/CommandParameter.h"

namespace AutoMacro {
namespace Command {
class Command {
 public:
    explicit Command(CommandParameter* p) :
        delayBeforeCommand(p->delayBeforeCommand),
        delayAfterCommand(p->delayAfterCommand) {
    }

    void execute() {
        Sleep(delayBeforeCommand);
        executeCommand();
        Sleep(delayAfterCommand);
    }

 protected:
    virtual void executeCommand() = 0;

    int delayBeforeCommand = 0;
    int delayAfterCommand = 0;
};
}  // namespace Command
}  // namespace AutoMacro
