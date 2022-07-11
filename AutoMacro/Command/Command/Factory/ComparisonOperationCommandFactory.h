#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Parameter/ComparisonOperationCommandParameter.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    ComparisonOperationCommandParameter* p);
DLL_EXPORTS std::shared_ptr<TCommand<bool>> createTCommand(
    ComparisonOperationCommandParameter* p);
}  // namespace Factory
}  // namespace AutoMacro
