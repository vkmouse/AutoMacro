#include "AutoMacro/Command/Command/Factory/LogicalOperationCommandFactory.h"

#include <memory>

#include "AutoMacro/Command/Command/Command/LogicalOperationCommand.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Command> createCommand(LogicalOperationCommandParameter* p) {
    auto command = createTCommand(p);
    return createCommand(command);
}

std::shared_ptr<TCommand<bool>> createTCommand(
        LogicalOperationCommandParameter* p) {
    return std::make_shared<Impl::LogicalOperationCommand>(p);
}
}  // namespace Factory
}  // namespace AutoMacro
