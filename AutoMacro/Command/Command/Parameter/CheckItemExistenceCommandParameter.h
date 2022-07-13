#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Parameter/CheckExistenceCommandParameter.h"

namespace AutoMacro {
class CheckItemExistenceCommandParameter
    : public CheckExistenceCommandParameter {
 public:
    CheckItemExistenceCommandParameter(Kvm kvm,
        std::shared_ptr<Detector> detector, float threshold)
        : CheckExistenceCommandParameter(kvm),
          detector(detector), threshold(threshold) {}

    std::shared_ptr<Detector> detector;
    float threshold;
    bool checkWithIndex = false;
    int index = -1;
};
}  // namespace AutoMacro
