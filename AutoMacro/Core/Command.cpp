#include "AutoMacro/Core/Command.h"

#include "AutoMacro/Core/Command/Commands.h"
#include "AutoMacro/Core/Command/CounterCommand.h"
#include "AutoMacro/Core/Command/EmptyCommand.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Command> createCommand() {
    return std::make_shared<Impl::EmptyCommand>();
}

std::shared_ptr<Command> createCommand(CommandsParameter* p) {
    return std::make_shared<Impl::Commands>(p);
}

std::shared_ptr<Command> createCommand(CounterCommandParameter* p) {
    return std::make_shared<Impl::CounterCommand>(p);
}
}  // namespace Factory
}  // namespace AutoMacro
