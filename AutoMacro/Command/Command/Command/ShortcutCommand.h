#pragma once
#include <vector>

#include "AutoMacro/Command/Command/Command/KvmCommand.h"
#include "AutoMacro/Command/Command/Parameter/ShortCutCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class ShortcutCommand : public KvmCommand<void> {
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
}  // namespace AutoMacro
