#pragma once
#include <memory>

#include "AutoMacro/Core/Command/KvmCommandParameter.h"

namespace AutoMacro {
class DelayCommandParameter : public KvmCommandParameter {
 public:
    DelayCommandParameter(Kvm kvm, int ms)
        : KvmCommandParameter(kvm), ms(ms) {}

    int ms;
};
}  // namespace AutoMacro
