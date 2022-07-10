#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Parameter/CounterCommandParameter.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    CounterCommandParameter* p);
DLL_EXPORTS std::shared_ptr<TCommand<void>> createTCommand(
    CounterCommandParameter* p);
}  // namespace Factory
}  // namespace AutoMacro
