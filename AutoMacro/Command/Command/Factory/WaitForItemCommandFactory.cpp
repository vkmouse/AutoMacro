#include "AutoMacro/Command/Command/Factory/WaitForItemCommandFactory.h"

#include <memory>

#include "AutoMacro/Command/Command/Command/WaitForItemCommand.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Command> createCommand(WaitForItemCommandParameter* p) {
    auto command = createTCommand(p);
    return createCommand(command);
}

std::shared_ptr<TCommand<void>> createTCommand(WaitForItemCommandParameter* p) {
    return std::make_shared<Impl::WaitForItemCommand>(p);
}
}  // namespace Factory
}  // namespace AutoMacro
