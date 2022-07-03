#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Cv/Command/WaitForCommandParameter.h"

namespace AutoMacro {
class WaitForItemsCommandParameter : public WaitForCommandParameter {
 public:
    WaitForItemsCommandParameter(
        Kvm kvm,
        std::vector<std::shared_ptr<Detector>> detectors,
        std::vector<int> indices,
        std::vector<float> thresholds)
        : WaitForCommandParameter(kvm),
          detectors(detectors),
          indices(indices),
          thresholds(thresholds) {}

    std::vector<std::shared_ptr<Detector>> detectors;
    std::vector<int> indices;
    std::vector<float> thresholds;
    bool waitForAllItems = false;
};
}  // namespace AutoMacro
