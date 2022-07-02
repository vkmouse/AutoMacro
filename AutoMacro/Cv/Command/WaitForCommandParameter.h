#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
class WaitForCommandParameter : public CommandParameter {
 public:
    WaitForCommandParameter(
        std::shared_ptr<Keyboard> keyboard,
        std::shared_ptr<Mouse> mouse,
        std::shared_ptr<VideoCapture> videoCapture,
        std::shared_ptr<Delay> delay)
        : CommandParameter(keyboard, mouse, videoCapture, delay) {}

    int delayBetweenRepeatitions = 0;
    bool waitForExists = true;
};
}  // namespace AutoMacro
