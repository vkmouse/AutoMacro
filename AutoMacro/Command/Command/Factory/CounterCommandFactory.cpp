#include "AutoMacro/Command/Command/Factory/CounterCommandFactory.h"

#include <memory>

#include "AutoMacro/Command/Command/Command/CounterCommand.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Command> createCommand(CounterCommandParameter* p) {
    auto command = createTCommand(p);
    return createCommand(command);
}

std::shared_ptr<TCommand<void>> createTCommand(CounterCommandParameter* p) {
    return std::make_shared<Impl::CounterCommand>(p);
}
}  // namespace Factory
}  // namespace AutoMacro
