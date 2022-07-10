#include "AutoMacro/Command/Command/Factory/CheckItemsExistenceCommandFactory.h"

#include <memory>

#include "AutoMacro/Command/Command/Parameter/CheckItemsExistenceCommandParameter.h"
#include "AutoMacro/Command/Command/Command/CheckItemsExistenceCommand.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Command> createCommand(
        CheckItemsExistenceCommandParameter* p) {
    auto command = createTCommand(p);
    return createCommand(command);
}

std::shared_ptr<TCommand<bool>> createTCommand(
        CheckItemsExistenceCommandParameter* p) {
    return std::make_shared<Impl::CheckItemsExistenceCommand>(p);
}
}  // namespace Factory
}  // namespace AutoMacro
