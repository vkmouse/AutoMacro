#pragma once
#include <memory>

#include "AutoMacro/Command/Command/CommandParameter.h"
#include "AutoMacro/Command/Command/KeyboardCommand.h"
#include "AutoMacro/Keyboard/Keyboard.h"

namespace AutoMacro {
namespace Command {
namespace Impl {
class DesktopSwitchCommand : public KeyboardCommand {
 public:
    explicit DesktopSwitchCommand(DesktopSwitchCommandParameter* p);

 protected:
    virtual void executeCommand();

 private:
    static void resetDesktop(
        std::shared_ptr<Keyboard> keyboard, int numDesktops);
    static void switchToNext(
        std::shared_ptr<Keyboard> keyboard, int times);
    static void switchToPrevious(
        std::shared_ptr<Keyboard> keyboard, int times);

    static int globalNumDesktops;
    static int currentDesktop;

    int numDesktops;
    int destination;
};
}  // namespace Impl
}  // namespace Command
}  // namespace AutoMacro
