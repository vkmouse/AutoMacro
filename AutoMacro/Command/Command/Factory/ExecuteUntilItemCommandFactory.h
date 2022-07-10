#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Parameter/ExecuteUntilItemCommandParameter.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    ExecuteUntilItemCommandParameter* p);
DLL_EXPORTS std::shared_ptr<TCommand<void>> createTCommand(
    ExecuteUntilItemCommandParameter* p);
}  // namespace Factory
}  // namespace AutoMacro
