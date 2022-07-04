#include "AutoMacro/Kvm/Command/MouseClickCommand.h"

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Impl {
MouseClickCommand::MouseClickCommand(MouseClickCommandParameter* p)
    : KvmCommand(p),
      button(p->button),
      delayBetweenMouseDownAndMouseUp(p->delayBetweenMouseDownAndMouseUp),
      delayBetweenRepeatitions(p->delayBetweenRepeatitions),
      repeatTimes(p->repeatTimes),
      enableMove(p->enableMove), x(p->x), y(p->y),
      delayBeforeMove(p->delayBeforeMove),
      delayAfterMove(p->delayAfterMove) {
}

void MouseClickCommand::executeCommand() {
    if (enableMove) {
        mouseMove();
    }

    if (repeatTimes >= 1) {
        mouseClick();
        for (int i = 1; i < repeatTimes; i++) {
            sleep(delayBetweenRepeatitions);
            mouseClick();
        }
    }
}

void MouseClickCommand::mouseClick() {
    mouseDown(button);
    sleep(delayBetweenMouseDownAndMouseUp);
    mouseUp(button);
}

void MouseClickCommand::mouseMove() {
    sleep(delayBeforeMove);
    KvmCommand::mouseMove(x, y);
    sleep(delayAfterMove);
}
}  // namespace Impl
}  // namespace AutoMacro
