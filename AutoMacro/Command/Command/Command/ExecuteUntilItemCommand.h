#pragma once
#include <memory>

#include "AutoMacro/Command/Command/Command/WhileCommand.h"
#include "AutoMacro/Command/Command/Parameter/ExecuteUntilItemCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class ExecuteUntilItemCommand : public WhileCommand {
 public:
    explicit ExecuteUntilItemCommand(ExecuteUntilItemCommandParameter* p);
};
}  // namespace Impl
}  // namespace AutoMacro
