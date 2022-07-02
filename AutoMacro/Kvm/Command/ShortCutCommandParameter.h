#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
class ShortcutCommandParameter : public CommandParameter {
 public:
    ShortcutCommandParameter(
        std::shared_ptr<Keyboard> keyboard,
        std::shared_ptr<Mouse> mouse,
        std::shared_ptr<VideoCapture> videoCapture,
        std::shared_ptr<Delay> delay,
        std::vector<KeyCode> keys)
        : CommandParameter(keyboard, mouse, videoCapture, delay),
          keys(keys) {}

    std::vector<KeyCode> keys;
    int delayBetweenEachPressKey = 0;
    int delayBetweenEachReleaseKey = 0;
    int delayBetweenPressKeyAndReleaseKey = 0;
    int delayBetweenRepeatitions = 0;
    int repeatTimes = 1;
};
}  // namespace AutoMacro
