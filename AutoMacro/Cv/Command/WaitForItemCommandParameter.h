#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Cv/Command/WaitForCommandParameter.h"

namespace AutoMacro {
class WaitForItemCommandParameter : public WaitForCommandParameter {
 public:
    WaitForItemCommandParameter(
        std::shared_ptr<Keyboard> keyboard,
        std::shared_ptr<Mouse> mouse,
        std::shared_ptr<VideoCapture> videoCapture,
        std::shared_ptr<Delay> delay,
        std::shared_ptr<Detector> detector,
        int index,
        float threshold)
        : WaitForCommandParameter(keyboard, mouse, videoCapture, delay),
          detector(detector),
          index(index),
          threshold(threshold) {}

    std::shared_ptr<Detector> detector;
    int index;
    float threshold;
};
}  // namespace AutoMacro
