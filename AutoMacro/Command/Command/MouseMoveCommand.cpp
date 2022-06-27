#include "AutoMacro/Command/Command/MouseMoveCommand.h"

#include <memory>

#include "AutoMacro/Command/Command/CommandParameter.h"
#include "AutoMacro/KbdMou/KbdMou.h"

namespace AutoMacro {
namespace Command {
namespace Impl {
MouseMoveCommand::MouseMoveCommand(MouseMoveCommandParameter* p) :
    MouseCommand(p), x(p->x), y(p->y) {
}

void MouseMoveCommand::executeCommand() {
    mouse()->mouseMove(x, y);
}
}  // namespace Impl
}  // namespace Command
}  // namespace AutoMacro
