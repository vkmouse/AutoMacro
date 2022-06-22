#include "AutoMacro/Command/Command/ShortcutCommand.h"

#include <Windows.h>
#include <memory>

#include "AutoMacro/Command/Command/CommandParameter.h"
#include "AutoMacro/KbdMou/KbdMou.h"

namespace AutoMacro {
namespace Command {
namespace Impl {
ShortcutCommand::ShortcutCommand(ShortcutCommandParameter* p) :
    KeyboardCommand(p),
    keys(p->keys),
    delayBetweenEachPressKey(p->delayBetweenEachPressKey),
    delayBetweenEachReleaseKey(p->delayBetweenEachReleaseKey),
    delayBetweenPressKeyAndReleaseKey(p->delayBetweenPressKeyAndReleaseKey),
    delayBetweenRepeatitions(p->delayBetweenRepeatitions),
    repeatTimes(p->repeatTimes) {
}

void ShortcutCommand::executeCommand() {
    if (repeatTimes >= 1) {
        pressAndReleaseKeys();
        for (int i = 1; i < repeatTimes; i++) {
            Sleep(delayBetweenRepeatitions);
            pressAndReleaseKeys();
        }
    }
}

void ShortcutCommand::pressKeys() {
    keyboard()->pressKey(keys.front());
    if (keys.size() > 1) {
        for (auto key = keys.begin() + 1; key != keys.end(); ++key) {
            Sleep(delayBetweenEachPressKey);
            keyboard()->pressKey(*key);
        }
    }
}

void ShortcutCommand::releaseKeys() {
    keyboard()->releaseKey(keys.back());
    if (keys.size() > 1) {
        for (auto key = keys.rbegin() + 1; key != keys.rend(); ++key) {
            Sleep(delayBetweenEachReleaseKey);
            keyboard()->releaseKey(*key);
        }
    }
}

void ShortcutCommand::pressAndReleaseKeys() {
    pressKeys();
    Sleep(delayBetweenPressKeyAndReleaseKey);
    releaseKeys();
}
}  // namespace Impl
}  // namespace Command
}  // namespace AutoMacro
