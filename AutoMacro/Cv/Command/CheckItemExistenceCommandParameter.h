#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Cv/Command/CheckExistenceCommandParameter.h"

namespace AutoMacro {
class CheckItemExistenceCommandParameter
    : public CheckExistenceCommandParameter {
 public:
    CheckItemExistenceCommandParameter(Kvm kvm,
        std::shared_ptr<Detector> detector, int index, float threshold)
        : CheckExistenceCommandParameter(kvm),
          detector(detector), index(index), threshold(threshold) {}

    std::shared_ptr<Detector> detector;
    int index;
    float threshold;
};
}  // namespace AutoMacro
