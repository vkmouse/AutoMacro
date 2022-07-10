#include "AutoMacro/Command/Command/Factory/ExecuteUntilItemCommandFactory.h"

#include <memory>

#include "AutoMacro/Command/Command/Command/ExecuteUntilItemCommand.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Command> createCommand(ExecuteUntilItemCommandParameter* p) {
    auto command = createTCommand(p);
    return createCommand(command);
}

std::shared_ptr<TCommand<void>> createTCommand(
        ExecuteUntilItemCommandParameter* p) {
    return std::make_shared<Impl::ExecuteUntilItemCommand>(p);
}
}  // namespace Factory
}  // namespace AutoMacro
