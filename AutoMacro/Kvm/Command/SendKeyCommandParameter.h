#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
class SendKeyCommandParameter : public KvmCommandParameter {
 public:
    SendKeyCommandParameter(Kvm kvm, KeyCode key)
        : KvmCommandParameter(kvm), key(key) {}

    KeyCode key;
    int delayBetweenPressKeyAndReleaseKey = 0;
    int delayBetweenRepeatitions = 0;
    int repeatTimes = 1;
};
}  // namespace AutoMacro
