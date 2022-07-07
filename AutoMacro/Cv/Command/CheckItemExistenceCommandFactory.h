#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Cv/Command/CheckExistenceCommand.h"
#include "AutoMacro/Cv/Command/CheckItemExistenceCommandParameter.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<TCommand<bool>> createTCommand(
    CheckItemExistenceCommandParameter* parameter);
}  // namespace Factory
}  // namespace AutoMacro
