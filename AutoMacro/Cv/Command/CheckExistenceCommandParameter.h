#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
class CheckExistenceCommandParameter : public KvmCommandParameter {
 public:
    explicit CheckExistenceCommandParameter(Kvm kvm)
        : KvmCommandParameter(kvm) {}

    bool isExpectedToExist = true;
};
}  // namespace AutoMacro
