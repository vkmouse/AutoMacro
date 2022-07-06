#pragma once
#include <memory>

#include "AutoMacro/Core/Command/Command.h"
#include "AutoMacro/Core/Command/CommandsParameter.h"
#include "AutoMacro/Core/Command/CounterCommandParameter.h"
#include "AutoMacro/Core/Command/DelayCommandParameter.h"
#include "AutoMacro/Core/Command/KvmCommand.h"
#include "AutoMacro/Core/Command/KvmCommandParameter.h"
#include "AutoMacro/Core/Command/WhileCommand.h"
#include "AutoMacro/Core/Command/WhileCommandParameter.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Command> createCommand();
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    CommandsParameter* p);
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    CounterCommandParameter* p);
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    DelayCommandParameter* p);

DLL_EXPORTS std::shared_ptr<TCommand<void>> createTCommand(
    CounterCommandParameter* p);
DLL_EXPORTS std::shared_ptr<TCommand<void>> createTCommand(
    DelayCommandParameter* p);

template<class T>
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    std::shared_ptr<TCommand<T>> command);
}  // namespace Factory
}  // namespace AutoMacro
