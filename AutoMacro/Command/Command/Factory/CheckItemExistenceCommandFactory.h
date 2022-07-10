#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Parameter/CheckItemExistenceCommandParameter.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    CheckItemExistenceCommandParameter* p);
DLL_EXPORTS std::shared_ptr<TCommand<bool>> createTCommand(
    CheckItemExistenceCommandParameter* p);
}  // namespace Factory
}  // namespace AutoMacro
