#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Command/Command/CommandParameter.h"
#include "AutoMacro/Command/Command/KeyboardCommand.h"
#include "AutoMacro/Keyboard/Keyboard.h"

namespace AutoMacro {
namespace Command {
namespace Impl {
class ShortcutCommand : public KeyboardCommand {
 public:
    explicit ShortcutCommand(ShortcutCommandParameter* p);

 protected:
    virtual void executeCommand();

 private:
    void pressKeys();
    void releaseKeys();
    void pressAndReleaseKeys();

    std::vector<KeyCode> keys;
    int delayBetweenEachPressKey;
    int delayBetweenEachReleaseKey;
    int delayBetweenPressKeyAndReleaseKey;
    int delayBetweenRepeatitions;
    int repeatTimes;
};
}  // namespace Impl
}  // namespace Command
}  // namespace AutoMacro
