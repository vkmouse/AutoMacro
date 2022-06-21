#pragma once
#include <memory>

#include "AutoMacro/Command/Command/Command.h"
#include "AutoMacro/Command/Command/CommandParameter.h"
#include "AutoMacro/Keyboard/Keyboard.h"

namespace AutoMacro {
namespace Command {
namespace Impl {
class KeyboardCommand : public Command {
 public:
    explicit KeyboardCommand(KeyboardCommandParameter* p);

 protected:
    std::shared_ptr<Keyboard> keyboard() const;

 private:
    std::shared_ptr<Keyboard> keyboard_;
};
}  // namespace Impl
}  // namespace Command
}  // namespace AutoMacro
