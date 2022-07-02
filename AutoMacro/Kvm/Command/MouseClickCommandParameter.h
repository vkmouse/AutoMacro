#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
class MouseClickCommandParameter : public CommandParameter {
 public:
    MouseClickCommandParameter(
        std::shared_ptr<Keyboard> keyboard,
        std::shared_ptr<Mouse> mouse,
        std::shared_ptr<VideoCapture> videoCapture,
        std::shared_ptr<Delay> delay,
        MouseButton button)
        : CommandParameter(keyboard, mouse, videoCapture, delay),
          button(button) {}

    MouseClickCommandParameter(
        std::shared_ptr<Keyboard> keyboard,
        std::shared_ptr<Mouse> mouse,
        std::shared_ptr<VideoCapture> videoCapture,
        std::shared_ptr<Delay> delay,
        MouseButton button,
        int x, int y)
        : CommandParameter(keyboard, mouse, videoCapture, delay),
          button(button), enableMove(true), x(x), y(y) {}

    MouseButton button;
    int delayBetweenMouseDownAndMouseUp = 0;
    int delayBetweenRepeatitions = 0;
    int repeatTimes = 1;

    bool enableMove = false;
    int x = 0;
    int y = 0;
    int delayBeforeMove = 0;
    int delayAfterMove = 0;
};
}  // namespace AutoMacro
