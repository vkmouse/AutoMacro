#include "AutoMacro/Command/Command/Factory/CommandsFactory.h"

#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Command/Commands.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<TCommand<void>> createTCommand(
        std::vector<std::shared_ptr<Command>> commands) {
    return std::make_shared<Impl::Commands>(commands);
}

std::shared_ptr<Command> createCommand(
        std::vector<std::shared_ptr<Command>> commands) {
    auto command = createTCommand(commands);
    return createCommand(command);
}
}  // namespace Factory
}  // namespace AutoMacro
