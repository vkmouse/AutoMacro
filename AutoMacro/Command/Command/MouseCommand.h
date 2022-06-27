#pragma once
#include <memory>

#include "AutoMacro/Command/Command/Command.h"
#include "AutoMacro/Command/Command/CommandParameter.h"
#include "AutoMacro/KbdMou/KbdMou.h"

namespace AutoMacro {
namespace Command {
namespace Impl {
class MouseCommand : public Command {
 public:
    explicit MouseCommand(MouseCommandParameter* p);

 protected:
    std::shared_ptr<Mouse> mouse() const;

 private:
    std::shared_ptr<Mouse> mouse_;
};
}  // namespace Impl
}  // namespace Command
}  // namespace AutoMacro
