#pragma once
#include "AutoMacro/Command/Command/Command/KvmCommand.h"
#include "AutoMacro/Command/Command/Parameter/MouseClickCommandParameter.h"

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
