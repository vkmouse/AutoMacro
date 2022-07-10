#pragma once
#include "AutoMacro/Command/Command/Parameter/KvmCommandParameter.h"

namespace AutoMacro {
class DelayCommandParameter : public KvmCommandParameter {
 public:
    explicit DelayCommandParameter(Kvm kvm)
        : KvmCommandParameter(kvm) {}

    int ms = 0;
};
}  // namespace AutoMacro
