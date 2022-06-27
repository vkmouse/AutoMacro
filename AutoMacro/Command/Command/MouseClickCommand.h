#pragma once
#include "AutoMacro/Command/Command/CommandParameter.h"
#include "AutoMacro/Command/Command/MouseCommand.h"
#include "AutoMacro/KbdMou/KbdMou.h"

namespace AutoMacro {
namespace Command {
namespace Impl {
class MouseClickCommand : public MouseCommand {
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

    bool enableMouseMove;
    MouseMoveCommandParameter mouseMoveCommandParameter;
};
}  // namespace Impl
}  // namespace Command
}  // namespace AutoMacro
