#include "AutoMacro/Command/Command/Factory/CheckItemExistenceCommandFactory.h"

#include <memory>

#include "AutoMacro/Command/Command/Parameter/CheckItemExistenceCommandParameter.h"
#include "AutoMacro/Command/Command/Command/CheckItemExistenceCommand.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Command> createCommand(
        CheckItemExistenceCommandParameter* p) {
    auto command = createTCommand(p);
    return createCommand(command);
}

std::shared_ptr<TCommand<bool>> createTCommand(
        CheckItemExistenceCommandParameter* p) {
    return std::make_shared<Impl::CheckItemExistenceCommand>(p);
}
}  // namespace Factory
}  // namespace AutoMacro
