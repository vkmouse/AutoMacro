#pragma once
#include <memory>

#include "AutoMacro/Command/Command/Command/WhileCommand.h"
#include "AutoMacro/Command/Command/Parameter/WaitForItemsCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class WaitForItemsCommand : public WhileCommand {
 public:
    explicit WaitForItemsCommand(WaitForItemsCommandParameter* p)
        : WhileCommand(p) {}
};
}  // namespace Impl
}  // namespace AutoMacro
