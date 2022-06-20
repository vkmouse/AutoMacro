#pragma once
#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Command {
class DLL_EXPORTS Command {
 public:
    Command();

    virtual void execute();

    int delayBeforeCommand = 0;
    int delayAfterCommand = 0;

 protected:
    virtual void executeCommand() = 0;
};
}  // namespace Command
}  // namespace AutoMacro
