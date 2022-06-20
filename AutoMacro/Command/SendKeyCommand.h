#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command.h"

namespace AutoMacro {
namespace Command {
class SendKeyCommand : public Command {
 public:
    DLL_EXPORTS SendKeyCommand(std::shared_ptr<Keyboard> keyboard, KeyCode key);

    int delayBetweenCommands = 0;
    int delayBetweenRepeatitions = 0;
    int repeatTimes = 1;

 protected:
    virtual void executeCommand();

 private:
    void pressAndRelease();

    std::shared_ptr<Keyboard> keyboard;
    KeyCode key;
};
}  // namespace Command
}  // namespace AutoMacro
