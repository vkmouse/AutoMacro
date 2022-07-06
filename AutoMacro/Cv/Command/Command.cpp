#include "AutoMacro/Cv/Command/Command.h"

#include <memory>

#include "AutoMacro/Cv/Command/RequestItemExistsCommand.h"
#include "AutoMacro/Cv/Command/RequestItemExistsCommandParameter.h"
#include "AutoMacro/Cv/Command/WaitForItemCommand.h"
#include "AutoMacro/Cv/Command/WaitForItemCommandParameter.h"
#include "AutoMacro/Cv/Command/WaitForItemsCommand.h"
#include "AutoMacro/Cv/Command/WaitForItemsCommandParameter.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Command> createCommand(
        WaitForItemCommandParameter* parameter) {
    return createCommand(createTCommand(parameter));
}

std::shared_ptr<Command> createCommand(
    WaitForItemsCommandParameter* parameter) {
    return createCommand(createTCommand(parameter));
}

std::shared_ptr<TCommand<void>> createTCommand(
    WaitForItemCommandParameter* parameter) {
    return std::make_shared<Impl::WaitForItemCommand>(parameter);
}

std::shared_ptr<TCommand<void>> createTCommand(
    WaitForItemsCommandParameter* parameter) {
    return std::make_shared<Impl::WaitForItemsCommand>(parameter);
}
std::shared_ptr<TCommand<bool>> createTCommand(
    RequestItemExistsCommandParameter* parameter) {
    return std::make_shared<Impl::RequestItemExistsCommand>(parameter);
}
}  // namespace Factory
}  // namespace AutoMacro
