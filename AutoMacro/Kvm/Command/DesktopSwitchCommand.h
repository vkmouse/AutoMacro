#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Kvm/Command/DesktopSwitchCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class DesktopSwitchCommand : public KvmCommand<void> {
 public:
    explicit DesktopSwitchCommand(DesktopSwitchCommandParameter* p);

 protected:
    virtual void executeCommand();

 private:
    void resetDesktop(int numDesktops);
    void switchToNext(int times);
    void switchToPrevious(int times);

    static int globalNumDesktops;
    static int currentDesktop;

    int numDesktops;
    int destination;
    int delayBetweemEachSwitch;
    std::shared_ptr<Command> afterSwitchCommand;
};
}  // namespace Impl
}  // namespace AutoMacro
