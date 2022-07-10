#include "AutoMacro/Command/Command/Factory/SendKeyCommandFactory.h"

#include <memory>

#include "AutoMacro/Command/Command/Parameter/SendKeyCommandParameter.h"
#include "AutoMacro/Command/Command/Command/SendKeyCommand.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Command> createCommand(SendKeyCommandParameter* p) {
    auto command = createTCommand(p);
    return createCommand(command);
}

std::shared_ptr<TCommand<void>> createTCommand(SendKeyCommandParameter* p) {
    return std::make_shared<Impl::SendKeyCommand>(p);
}
}  // namespace Factory
}  // namespace AutoMacro
