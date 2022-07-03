#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
class WaitForCommandParameter : public CommandParameter {
 public:
    explicit WaitForCommandParameter(Kvm kvm) : CommandParameter(kvm) {}

    int delayBetweenRepeatitions = 0;
    bool waitForExists = true;
};
}  // namespace AutoMacro
