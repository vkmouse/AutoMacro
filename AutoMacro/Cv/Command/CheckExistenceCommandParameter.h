#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
class CheckExistenceCommandParameter : public KvmCommandParameter {
 public:
    CheckExistenceCommandParameter(Kvm kvm, bool isExpectedToExist)
        : KvmCommandParameter(kvm), isExpectedToExist(isExpectedToExist) {}

    bool isExpectedToExist;
};
}  // namespace AutoMacro
