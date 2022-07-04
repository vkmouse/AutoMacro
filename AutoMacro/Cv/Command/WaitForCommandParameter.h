#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
class WaitForCommandParameter : public KvmCommandParameter {
 public:
    explicit WaitForCommandParameter(Kvm kvm) : KvmCommandParameter(kvm) {}

    int delayBetweenRepeatitions = 0;
    bool waitForExists = true;
};
}  // namespace AutoMacro
