#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Cv/Command/WaitForCommandParameter.h"

namespace AutoMacro {
class WaitForItemsCommandParameter : public WaitForCommandParameter {
 public:
    WaitForItemsCommandParameter(
        std::shared_ptr<Keyboard> keyboard,
        std::shared_ptr<Mouse> mouse,
        std::shared_ptr<VideoCapture> videoCapture,
        std::shared_ptr<Delay> delay,
        std::vector<std::shared_ptr<Detector>> detectors,
        std::vector<int> indices,
        std::vector<float> thresholds)
        : WaitForCommandParameter(keyboard, mouse, videoCapture, delay),
          detectors(detectors),
          indices(indices),
          thresholds(thresholds) {}

    std::vector<std::shared_ptr<Detector>> detectors;
    std::vector<int> indices;
    std::vector<float> thresholds;
    bool waitForAllItems = false;
};
}  // namespace AutoMacro
