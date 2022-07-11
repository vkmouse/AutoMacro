#include "AutoMacro/Command/Command/Factory/ArithmeticOperationCommandFactory.h"

#include <memory>

#include "AutoMacro/Command/Command/Command/ArithmeticOperationCommand.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Command> createCommand(ArithmeticOperationCommandParameter* p) {
    auto command = createTCommand(p);
    return createCommand(command);
}

std::shared_ptr<TCommand<void>> createTCommand(
        ArithmeticOperationCommandParameter* p) {
    return std::make_shared<Impl::ArithmeticOperationCommand>(p);
}
}  // namespace Factory
}  // namespace AutoMacro
