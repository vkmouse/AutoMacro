#include "AutoMacro/Command/SendKeyCommand.h"

#include <Windows.h>
#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Command {
SendKeyCommand::SendKeyCommand(
    std::shared_ptr<Keyboard> keyboard,
    KeyCode key) :
    keyboard(keyboard),
    key(key),
    delayBetweenCommands(0),
    delayBetweenRepeatitions(0),
    repeatTimes(1) {
}

void SendKeyCommand::executeCommand() {
    if (repeatTimes >= 1) {
        pressAndRelease();
        for (int i = 1; i < repeatTimes; i++) {
            Sleep(delayBetweenRepeatitions);
            pressAndRelease();
        }
    }
}

void SendKeyCommand::pressAndRelease() {
    keyboard->pressKey(key);
    Sleep(delayBetweenCommands);
    keyboard->releaseKey(key);
}
}  // namespace Command
}  // namespace AutoMacro
