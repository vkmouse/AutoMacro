#pragma once
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Kvm/Command/ShortcutCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class ShortcutCommand : public KvmCommand {
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
