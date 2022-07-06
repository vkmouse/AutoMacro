#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Cv/Command/RequestItemExistsCommandParameter.h"
#include "AutoMacro/Cv/Command/WaitForItemCommandParameter.h"
#include "AutoMacro/Cv/Command/WaitForItemsCommandParameter.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    WaitForItemCommandParameter* parameter);
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    WaitForItemsCommandParameter* parameter);

DLL_EXPORTS std::shared_ptr<TCommand<void>> createTCommand(
    WaitForItemCommandParameter* parameter);
DLL_EXPORTS std::shared_ptr<TCommand<void>> createTCommand(
    WaitForItemsCommandParameter* parameter);
DLL_EXPORTS std::shared_ptr<TCommand<bool>> createTCommand(
    RequestItemExistsCommandParameter* parameter);
}  // namespace Factory
}  // namespace AutoMacro
