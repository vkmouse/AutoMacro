#pragma once
#include "AutoMacro/Command/Command/MouseCommand.h"
#include "AutoMacro/Command/Command/CommandParameter.h"
#include "AutoMacro/KbdMou/KbdMou.h"

namespace AutoMacro {
namespace Command {
namespace Impl {
class MouseMoveCommand : public MouseCommand {
 public:
    explicit MouseMoveCommand(MouseMoveCommandParameter* p);

 protected:
    virtual void executeCommand();

 private:
    int x;
    int y;
};
}  // namespace Impl
}  // namespace Command
}  // namespace AutoMacro
