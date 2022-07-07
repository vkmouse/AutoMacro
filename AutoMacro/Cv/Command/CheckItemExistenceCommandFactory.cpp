#include "AutoMacro/Cv/Command/CheckItemExistenceCommandFactory.h"

#include "AutoMacro/Cv/Command/CheckItemExistenceCommand.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<TCommand<bool>> createTCommand(
    CheckItemExistenceCommandParameter* parameter) {
    return std::make_shared<Impl::CheckItemExistenceCommand>(parameter);
}
}  // namespace Factory
}  // namespace AutoMacro
