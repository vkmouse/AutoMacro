#pragma once
#include <memory>

#include "AutoMacro/Command/Command/Command/WhileCommand.h"
#include "AutoMacro/Command/Command/Parameter/WaitForItemCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class WaitForItemCommand : public WhileCommand {
 public:
    explicit WaitForItemCommand(WaitForItemCommandParameter* p)
        : WhileCommand(p) {}
};
}  // namespace Impl
}  // namespace AutoMacro
