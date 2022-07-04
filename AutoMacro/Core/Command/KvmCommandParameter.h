#pragma once
#include "AutoMacro/Core/Kvm/Kvm.h"

namespace AutoMacro {
class KvmCommandParameter {
 public:
    explicit KvmCommandParameter(Kvm kvm) : kvm(kvm) {}

    Kvm kvm;
    int delayBeforeCommand = 0;
    int delayAfterCommand = 0;
};
}  // namespace AutoMacro
