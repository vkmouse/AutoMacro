#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Parameter/ExecuteUntilItemsCommandParameter.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    ExecuteUntilItemsCommandParameter* p);
DLL_EXPORTS std::shared_ptr<TCommand<void>> createTCommand(
    ExecuteUntilItemsCommandParameter* p);
}  // namespace Factory
}  // namespace AutoMacro
