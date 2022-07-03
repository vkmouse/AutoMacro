#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
class DesktopSwitchCommandParameter : public CommandParameter {
 public:
    DesktopSwitchCommandParameter(Kvm kvm, int numDesktops, int destination)
        : CommandParameter(kvm),
          numDesktops(numDesktops),
          destination(destination) {}

    int numDesktops;
    int destination;
    int delayBetweemEachSwitch = 0;
};
}  // namespace AutoMacro
