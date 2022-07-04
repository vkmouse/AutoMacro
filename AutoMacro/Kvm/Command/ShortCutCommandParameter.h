#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
class ShortcutCommandParameter : public KvmCommandParameter {
 public:
    ShortcutCommandParameter(Kvm kvm, std::vector<KeyCode> keys)
        : KvmCommandParameter(kvm), keys(keys) {}

    std::vector<KeyCode> keys;
    int delayBetweenEachPressKey = 0;
    int delayBetweenEachReleaseKey = 0;
    int delayBetweenPressKeyAndReleaseKey = 0;
    int delayBetweenRepeatitions = 0;
    int repeatTimes = 1;
};
}  // namespace AutoMacro
