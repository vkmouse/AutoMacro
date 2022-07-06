#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Cv/Command/WaitForItemCommandParameter.h"
#include "AutoMacro/Cv/Command/WaitForItemsCommandParameter.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    WaitForItemCommandParameter* parameter);
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    WaitForItemsCommandParameter* parameter);
}  // namespace Factory
}  // namespace AutoMacro
