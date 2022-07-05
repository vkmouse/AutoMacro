#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
class DesktopSwitchCommandParameter : public KvmCommandParameter {
 public:
    DesktopSwitchCommandParameter(Kvm kvm, int numDesktops, int destination)
        : KvmCommandParameter(kvm),
          numDesktops(numDesktops),
          destination(destination) {}

    int numDesktops;
    int destination;
    int delayBetweemEachSwitch = 0;
    std::shared_ptr<Command> afterSwitchCommand = Factory::createCommand();
};
}  // namespace AutoMacro
