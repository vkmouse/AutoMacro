#include "AutoMacro/Command/Command/KeyboardCommand.h"

#include <memory>

#include "AutoMacro/Command/Command/CommandParameter.h"
#include "AutoMacro/Keyboard/Keyboard.h"

namespace AutoMacro {
namespace Command {
namespace Impl {
KeyboardCommand::KeyboardCommand(KeyboardCommandParameter* p) :
    Command(p),
    keyboard_(p->keyboard) {
}

std::shared_ptr<Keyboard> KeyboardCommand::keyboard() const {
    return keyboard_;
}
}  // namespace Impl
}  // namespace Command
}  // namespace AutoMacro
