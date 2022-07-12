#pragma once
#include <memory>

#include "AutoMacro/Command/Command/Command/ExecuteUntilItemsCommand.h"
#include "AutoMacro/Command/Command/Parameter/WaitForItemsCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class WaitForItemsCommand : public ExecuteUntilItemsCommand {
 public:
    explicit WaitForItemsCommand(WaitForItemsCommandParameter* p);
};
}  // namespace Impl
}  // namespace AutoMacro
