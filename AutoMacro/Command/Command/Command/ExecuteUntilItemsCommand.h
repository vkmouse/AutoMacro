#pragma once
#include <memory>

#include "AutoMacro/Command/Command/Command/WhileCommand.h"
#include "AutoMacro/Command/Command/Parameter/ExecuteUntilItemsCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class ExecuteUntilItemsCommand : public WhileCommand {
 public:
    explicit ExecuteUntilItemsCommand(ExecuteUntilItemsCommandParameter* p);
};
}  // namespace Impl
}  // namespace AutoMacro
