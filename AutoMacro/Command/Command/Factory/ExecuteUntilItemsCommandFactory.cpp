#include "AutoMacro/Command/Command/Factory/ExecuteUntilItemsCommandFactory.h"

#include <memory>

#include "AutoMacro/Command/Command/Command/ExecuteUntilItemsCommand.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Command> createCommand(ExecuteUntilItemsCommandParameter* p) {
    auto command = createTCommand(p);
    return createCommand(command);
}

std::shared_ptr<TCommand<void>> createTCommand(
        ExecuteUntilItemsCommandParameter* p) {
    return std::make_shared<Impl::ExecuteUntilItemsCommand>(p);
}
}  // namespace Factory
}  // namespace AutoMacro
