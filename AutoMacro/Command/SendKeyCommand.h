#pragma once
#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/Keyboard.h"
#include "AutoMacro/Command/Command.h"

namespace AutoMacro {
namespace Command {
class DLL_EXPORTS SendKeyCommandParameter {
 public:
    explicit SendKeyCommandParameter(KeyCode key) : key(key) {}

    int delayBeforeCommand = 0;
    int delayAfterCommand = 0;
    int delayBetweenCommands = 0;
    int delayBetweenRepeatitions = 0;
    int repeatTimes = 1;
    KeyCode key;
};

class DLL_EXPORTS SendKeyCommand : public Command {
 public:
    SendKeyCommand(Keyboard* keyboard, SendKeyCommandParameter parameter);

    virtual void execute();

 private:
    void pressAndRelease();

    Keyboard* keyboard_;
    KeyCode key_;
    int delayBeforeCommand_ = 0;
    int delayAfterCommand_ = 0;
    int delayBetweenCommands_ = 0;
    int delayBetweenRepeatitions_ = 0;
    int repeatTimes_ = 1;
};
}  // namespace Command
}  // namespace AutoMacro
