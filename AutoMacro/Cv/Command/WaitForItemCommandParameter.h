#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Cv/Command/WaitForCommandParameter.h"

namespace AutoMacro {
class WaitForItemCommandParameter : public WaitForCommandParameter {
 public:
    WaitForItemCommandParameter(
        Kvm kvm,
        std::shared_ptr<Detector> detector,
        int index, float threshold)
        : WaitForCommandParameter(kvm),
          detector(detector),
          index(index),
          threshold(threshold) {}

    std::shared_ptr<Detector> detector;
    int index;
    float threshold;
};
}  // namespace AutoMacro
