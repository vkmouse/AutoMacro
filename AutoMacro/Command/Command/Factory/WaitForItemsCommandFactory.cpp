#include "AutoMacro/Command/Command/Factory/WaitForItemsCommandFactory.h"

#include <memory>

#include "AutoMacro/Command/Command/Command/WaitForItemsCommand.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Command> createCommand(WaitForItemsCommandParameter* p) {
    auto command = createTCommand(p);
    return createCommand(command);
}

std::shared_ptr<TCommand<void>> createTCommand(
        WaitForItemsCommandParameter* p) {
    return std::make_shared<Impl::WaitForItemsCommand>(p);
}
}  // namespace Factory
}  // namespace AutoMacro
