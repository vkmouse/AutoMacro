#pragma once
#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Kvm/Command/MouseClickCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class MouseClickCommand : public KvmCommand<void> {
 public:
    explicit MouseClickCommand(MouseClickCommandParameter* p);

 protected:
    virtual void executeCommand();

 private:
    void mouseClick();
    void mouseMove();

    MouseButton button;
    int delayBetweenMouseDownAndMouseUp;
    int delayBetweenRepeatitions;
    int repeatTimes;

    bool enableMove;
    int x;
    int y;
    int delayBeforeMove;
    int delayAfterMove;
};
}  // namespace Impl
}  // namespace AutoMacro
