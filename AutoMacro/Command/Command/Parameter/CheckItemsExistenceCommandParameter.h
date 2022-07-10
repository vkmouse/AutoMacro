#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Parameter/CheckExistenceCommandParameter.h"

namespace AutoMacro {
class CheckItemsExistenceCommandParameter
    : public CheckExistenceCommandParameter {
 public:
    CheckItemsExistenceCommandParameter(Kvm kvm,
        std::vector<std::shared_ptr<Detector>> detectors,
        std::vector<int> indices,
        std::vector<float> thresholds)
        : CheckExistenceCommandParameter(kvm),
          detectors(detectors), indices(indices), thresholds(thresholds) {}

    std::vector<std::shared_ptr<Detector>> detectors;
    std::vector<int> indices;
    std::vector<float> thresholds;
    bool isExpectedToAllExist = false;
};
}  // namespace AutoMacro
