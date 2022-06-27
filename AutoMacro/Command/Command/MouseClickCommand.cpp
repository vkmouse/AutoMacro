#include "AutoMacro/Command/Command/MouseClickCommand.h"

#include "AutoMacro/Command/Command/CommandParameter.h"
#include "AutoMacro/Command/Command/MouseMoveCommand.h"
#include "AutoMacro/KbdMou/KbdMou.h"

namespace AutoMacro {
namespace Command {
namespace Impl {
MouseClickCommand::MouseClickCommand(MouseClickCommandParameter* p) :
    MouseCommand(p),
    button(p->button),
    delayBetweenMouseDownAndMouseUp(p->delayBetweenMouseDownAndMouseUp),
    delayBetweenRepeatitions(p->delayBetweenRepeatitions),
    repeatTimes(p->repeatTimes),
    enableMouseMove(p->enableMouseMove),
    mouseMoveCommandParameter(p->mouseMoveCommandParameter) {
}

void MouseClickCommand::executeCommand() {
    if (enableMouseMove) {
        mouseMove();
    }

    if (repeatTimes >= 1) {
        mouseClick();
        for (int i = 1; i < repeatTimes; i++) {
            Sleep(delayBetweenRepeatitions);
            mouseClick();
        }
    }
}

void MouseClickCommand::mouseClick() {
    mouse()->mouseDown(button);
    Sleep(delayBetweenMouseDownAndMouseUp);
    mouse()->mouseUp(button);
}

void MouseClickCommand::mouseMove() {
    MouseMoveCommand command(&mouseMoveCommandParameter);
    command.execute();
}
}  // namespace Impl
}  // namespace Command
}  // namespace AutoMacro
