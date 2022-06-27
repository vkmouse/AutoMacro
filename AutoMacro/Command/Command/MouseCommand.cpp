#include "AutoMacro/Command/Command/MouseCommand.h"

#include <memory>

#include "AutoMacro/Command/Command/CommandParameter.h"
#include "AutoMacro/KbdMou/KbdMou.h"

namespace AutoMacro {
namespace Command {
namespace Impl {
MouseCommand::MouseCommand(MouseCommandParameter* p) :
    Command(p),
    mouse_(p->mouse) {
}

std::shared_ptr<Mouse> MouseCommand::mouse() const {
    return mouse_;
}
}  // namespace Impl
}  // namespace Command
}  // namespace AutoMacro
