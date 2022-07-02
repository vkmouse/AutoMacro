#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
class DesktopSwitchCommandParameter : public CommandParameter {
 public:
    DesktopSwitchCommandParameter(
        std::shared_ptr<Keyboard> keyboard,
        std::shared_ptr<Mouse> mouse,
        std::shared_ptr<VideoCapture> videoCapture,
        std::shared_ptr<Delay> delay,
        int numDesktops,
        int destination)
        : CommandParameter(keyboard, mouse, videoCapture, delay),
          numDesktops(numDesktops),
          destination(destination) {}

    int numDesktops;
    int destination;
    int delayBetweemEachSwitch = 0;
};
}  // namespace AutoMacro
