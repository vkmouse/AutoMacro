#pragma once
#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Kvm/Command/SendKeyCommandParameter.h"

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
