#include "AutoMacro/Command/Command/Factory/ComparisonOperationCommandFactory.h"

#include <memory>

#include "AutoMacro/Command/Command/Command/ComparisonOperationCommand.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Command> createCommand(ComparisonOperationCommandParameter* p) {
    auto command = createTCommand(p);
    return createCommand(command);
}

std::shared_ptr<TCommand<bool>> createTCommand(
        ComparisonOperationCommandParameter* p) {
    return std::make_shared<Impl::ComparisonOperationCommand>(p);
}
}  // namespace Factory
}  // namespace AutoMacro
