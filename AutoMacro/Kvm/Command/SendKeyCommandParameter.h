#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
class SendKeyCommandParameter : public CommandParameter {
 public:
    SendKeyCommandParameter(
        std::shared_ptr<Keyboard> keyboard,
        std::shared_ptr<Mouse> mouse,
        std::shared_ptr<VideoCapture> videoCapture,
        std::shared_ptr<Delay> delay,
        KeyCode key)
        : CommandParameter(keyboard, mouse, videoCapture, delay),
          key(key) {}

    KeyCode key;
    int delayBetweenPressKeyAndReleaseKey = 0;
    int delayBetweenRepeatitions = 0;
    int repeatTimes = 1;
};
}  // namespace AutoMacro
