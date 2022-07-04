#pragma once
#include <memory>

#include "AutoMacro/Core/Command/Command.h"
#include "AutoMacro/Core/Command/CommandsParameter.h"
#include "AutoMacro/Core/Command/CounterCommandParameter.h"
#include "AutoMacro/Core/Command/KvmCommand.h"
#include "AutoMacro/Core/Command/KvmCommandParameter.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Command> createCommand();
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    CommandsParameter* p);
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    CounterCommandParameter* p);
}  // namespace Factory
}  // namespace AutoMacro
