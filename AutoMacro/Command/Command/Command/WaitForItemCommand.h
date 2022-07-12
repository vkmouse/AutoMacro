#pragma once
#include <memory>

#include "AutoMacro/Command/Command/Command/ExecuteUntilItemCommand.h"
#include "AutoMacro/Command/Command/Parameter/WaitForItemCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class WaitForItemCommand : public ExecuteUntilItemCommand {
 public:
    explicit WaitForItemCommand(WaitForItemCommandParameter* p);
};
}  // namespace Impl
}  // namespace AutoMacro
