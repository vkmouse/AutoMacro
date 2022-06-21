#pragma once
#include <memory>

#include "AutoMacro/Command/Command/CommandParameter.h"
#include "AutoMacro/Command/Command/KeyboardCommand.h"
#include "AutoMacro/Keyboard/Keyboard.h"

namespace AutoMacro {
namespace Command {
namespace Impl {
class SendKeyCommand : public KeyboardCommand {
 public:
    explicit SendKeyCommand(SendKeyCommandParameter* p);

 protected:
    virtual void executeCommand();

 private:
    void pressAndRelease();

    KeyCode key;
    int delayBetweenCommands;
    int delayBetweenRepeatitions;
    int repeatTimes;
};
}  // namespace Impl
}  // namespace Command
}  // namespace AutoMacro
