#include "AutoMacro/Kvm/Command/ShortcutCommand.h"

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Kvm/Command/ShortCutCommandParameter.h"

namespace AutoMacro {
namespace Impl {
ShortcutCommand::ShortcutCommand(ShortcutCommandParameter* p)
    : KvmCommand(p),
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
            sleep(delayBetweenRepeatitions);
            pressAndReleaseKeys();
        }
    }
}

void ShortcutCommand::pressKeys() {
    pressKey(keys.front());
    if (keys.size() > 1) {
        for (auto key = keys.begin() + 1; key != keys.end(); ++key) {
            sleep(delayBetweenEachPressKey);
            pressKey(*key);
        }
    }
}

void ShortcutCommand::releaseKeys() {
    releaseKey(keys.back());
    if (keys.size() > 1) {
        for (auto key = keys.rbegin() + 1; key != keys.rend(); ++key) {
            sleep(delayBetweenEachReleaseKey);
            releaseKey(*key);
        }
    }
}

void ShortcutCommand::pressAndReleaseKeys() {
    pressKeys();
    sleep(delayBetweenPressKeyAndReleaseKey);
    releaseKeys();
}
}  // namespace Impl
}  // namespace AutoMacro
