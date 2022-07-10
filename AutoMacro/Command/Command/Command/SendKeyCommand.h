#pragma once
#include "AutoMacro/Command/Command/Command/KvmCommand.h"
#include "AutoMacro/Command/Command/Parameter/SendKeyCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class SendKeyCommand : public KvmCommand<void> {
 public:
    explicit SendKeyCommand(SendKeyCommandParameter* p);

 protected:
    virtual void executeCommand();

 private:
    void pressAndRelease();

    KeyCode key;
    int delayBetweenPressKeyAndReleaseKey;
    int delayBetweenRepeatitions;
    int repeatTimes;
};
}  // namespace Impl
}  // namespace AutoMacro
