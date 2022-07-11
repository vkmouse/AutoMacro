#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Parameter/LogicalOperationCommandParameter.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    LogicalOperationCommandParameter* p);
DLL_EXPORTS std::shared_ptr<TCommand<bool>> createTCommand(
    LogicalOperationCommandParameter* p);
}  // namespace Factory
}  // namespace AutoMacro
