#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Parameter/CheckItemsExistenceCommandParameter.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    CheckItemsExistenceCommandParameter* p);
DLL_EXPORTS std::shared_ptr<TCommand<bool>> createTCommand(
    CheckItemsExistenceCommandParameter* p);
}  // namespace Factory
}  // namespace AutoMacro
