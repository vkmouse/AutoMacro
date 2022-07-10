#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Parameter/WaitForItemsCommandParameter.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    WaitForItemsCommandParameter* p);
DLL_EXPORTS std::shared_ptr<TCommand<void>> createTCommand(
    WaitForItemsCommandParameter* p);
}  // namespace Factory
}  // namespace AutoMacro
