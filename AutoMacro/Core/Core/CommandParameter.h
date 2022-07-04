#pragma once
#include <memory>

#include "AutoMacro/Core/Kvm/Kvm.h"

namespace AutoMacro {
class CommandParameter {
 public:
    explicit CommandParameter(Kvm kvm) : kvm(kvm) {}

    Kvm kvm;
    int delayBeforeCommand = 0;
    int delayAfterCommand = 0;
};
}  // namespace AutoMacro
