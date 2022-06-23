#pragma once
#include <memory>

#include "AutoMacro/Command/Command/CommandParameter.h"
#include "AutoMacro/Command/Command/KeyboardCommand.h"
#include "AutoMacro/KbdMou/KbdMou.h"

namespace AutoMacro {
namespace Command {
namespace Impl {
class DesktopSwitchCommand : public KeyboardCommand {
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
};
}  // namespace Impl
}  // namespace Command
}  // namespace AutoMacro
