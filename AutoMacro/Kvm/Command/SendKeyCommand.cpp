#include "AutoMacro/Kvm/Command/SendKeyCommand.h"

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Kvm/Command/SendKeyCommandParameter.h"

namespace AutoMacro {
namespace Impl {
SendKeyCommand::SendKeyCommand(SendKeyCommandParameter* p)
    : KvmCommand(p),
      key(p->key),
      delayBetweenPressKeyAndReleaseKey(p->delayBetweenPressKeyAndReleaseKey),
      delayBetweenRepeatitions(p->delayBetweenRepeatitions),
      repeatTimes(p->repeatTimes) {
}

void SendKeyCommand::executeCommand() {
    if (repeatTimes >= 1) {
        pressAndRelease();
        for (int i = 1; i < repeatTimes; i++) {
            sleep(delayBetweenRepeatitions);
            pressAndRelease();
        }
    }
}

void SendKeyCommand::pressAndRelease() {
    pressKey(key);
    sleep(delayBetweenPressKeyAndReleaseKey);
    releaseKey(key);
}
}  // namespace Impl
}  // namespace AutoMacro
