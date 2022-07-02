#pragma once
#include <memory>

#include "AutoMacro/Core/Core/Delay.h"
#include "AutoMacro/Core/Core/Keyboard.h"
#include "AutoMacro/Core/Core/Mouse.h"
#include "AutoMacro/Core/Core/VideoCapture.h"

namespace AutoMacro {
class CommandParameter {
 public:
    CommandParameter(std::shared_ptr<Keyboard> keyboard,
                     std::shared_ptr<Mouse> mouse,
                     std::shared_ptr<VideoCapture> videoCapture,
                     std::shared_ptr<Delay> delay)
                     : keyboard(keyboard),
                       mouse(mouse),
                       videoCapture(videoCapture),
                       delay(delay) {}

    std::shared_ptr<Keyboard> keyboard;
    std::shared_ptr<Mouse> mouse;
    std::shared_ptr<VideoCapture> videoCapture;
    std::shared_ptr<Delay> delay;
    int delayBeforeCommand = 0;
    int delayAfterCommand = 0;
};
}  // namespace AutoMacro
