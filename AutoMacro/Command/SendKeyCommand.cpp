#include "AutoMacro/Command/SendKeyCommand.h"

#include <Windows.h>

#include "AutoMacro/Core/Keyboard.h"

namespace AutoMacro {
namespace Command {
SendKeyCommand::SendKeyCommand(
    Keyboard* keyboard,
    SendKeyCommandParameter parameter) :
    keyboard_(keyboard) {
    key_ = parameter.key;
    delayBeforeCommand_ = parameter.delayBeforeCommand;
    delayAfterCommand_ = parameter.delayAfterCommand;
    delayBetweenCommands_ = parameter.delayBetweenCommands;
    delayBetweenRepeatitions_ = parameter.delayBetweenRepeatitions;
    repeatTimes_ = parameter.repeatTimes;
}

void SendKeyCommand::execute() {
    Sleep(delayBeforeCommand_);
    if (repeatTimes_ >= 1) {
        pressAndRelease();
        for (int i = 1; i < repeatTimes_; i++) {
            Sleep(delayBetweenRepeatitions_);
            pressAndRelease();
        }
    }
    Sleep(delayAfterCommand_);
}

void SendKeyCommand::pressAndRelease() {
    keyboard_->pressKey(key_);
    Sleep(delayBetweenCommands_);
    keyboard_->releaseKey(key_);
}
}  // namespace Command
}  // namespace AutoMacro
