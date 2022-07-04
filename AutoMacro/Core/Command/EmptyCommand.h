#pragma once
#include "AutoMacro/Core/Command/Command.h"

namespace AutoMacro {
namespace Impl {
class EmptyCommand : public Command {
 public:
    void execute() override {}
};
}  // namespace Impl
}  // namespace AutoMacro
