#include "AutoMacro/Command/Command/SendKeyCommand.h"

#include <Windows.h>
#include <memory>

#include "AutoMacro/Command/Command/CommandParameter.h"
#include "AutoMacro/Keyboard/Keyboard.h"

namespace AutoMacro {
namespace Command {
namespace Impl {
SendKeyCommand::SendKeyCommand(SendKeyCommandParameter* p) :
    Command(p),
    keyboard(p->keyboard),
    key(p->key),
    delayBetweenCommands(p->delayBetweenCommands),
    delayBetweenRepeatitions(p->delayBetweenRepeatitions),
    repeatTimes(p->repeatTimes) {
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
}  // namespace Impl
}  // namespace Command
}  // namespace AutoMacro
