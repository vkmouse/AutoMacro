#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Cv/Command/WaitForItemCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class WaitForItemCommand : public WhileCommand {
 public:
    explicit WaitForItemCommand(WaitForItemCommandParameter* p)
        : WhileCommand(p) {}
};
}  // namespace Impl
}  // namespace AutoMacro
