#include "AutoMacro/Core/Command.h"

#include "AutoMacro/Core/Command/Commands.h"
#include "AutoMacro/Core/Command/CounterCommand.h"
#include "AutoMacro/Core/Command/EmptyCommand.h"
#include "AutoMacro/Core/Command/TCommandAdapter.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Command> createCommand() {
    return std::make_shared<Impl::EmptyCommand>();
}

std::shared_ptr<Command> createCommand(CommandsParameter* p) {
    return std::make_shared<Impl::Commands>(p);
}

std::shared_ptr<Command> createCommand(CounterCommandParameter* p) {
    auto command = createTCommand(p);
    return createCommand(command);
}

std::shared_ptr<TCommand<void>> createTCommand(CounterCommandParameter* p) {
    return std::make_shared<Impl::CounterCommand>(p);
}

template<class T>
std::shared_ptr<Command> createCommand(std::shared_ptr<TCommand<T>> command) {
    return std::make_shared<Impl::TCommandAdapter<T>>(command);
}
}  // namespace Factory
}  // namespace AutoMacro
