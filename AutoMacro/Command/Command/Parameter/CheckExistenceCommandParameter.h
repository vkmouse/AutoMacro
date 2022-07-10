#pragma once
#include "AutoMacro/Command/Command/Parameter/KvmCommandParameter.h"

namespace AutoMacro {
class CheckExistenceCommandParameter : public KvmCommandParameter {
 public:
    explicit CheckExistenceCommandParameter(Kvm kvm)
        : KvmCommandParameter(kvm) {}

    bool isExpectedToExist = true;
};
}  // namespace AutoMacro
