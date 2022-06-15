#pragma once
#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/Keyboard.h"
#include "AutoMacro/Command/Command.h"

namespace AutoMacro {
namespace Command {
class DLL_EXPORTS SendKeyCommand : public Command {
 public:
    SendKeyCommand(Keyboard* keyboard, KeyCode key);

    int delayBetweenCommands = 0;
    int delayBetweenRepeatitions = 0;
    int repeatTimes = 1;

 protected:
    virtual void executeCommand();

 private:
    void pressAndRelease();

    Keyboard* keyboard;
    KeyCode key;
};
}  // namespace Command
}  // namespace AutoMacro
