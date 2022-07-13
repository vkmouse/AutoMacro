#include "AutoMacro/Command/Command/Command/ExecuteUntilItemsCommand.h"

#include "AutoMacro/Command/Command/Factory/CheckItemsExistenceCommandFactory.h"
#include "AutoMacro/Command/Command/Factory/LogicalOperationCommandFactory.h"
#include "AutoMacro/Command/Command/Parameter/ExecuteUntilItemsCommandParameter.h"

namespace AutoMacro {
namespace Impl {
ExecuteUntilItemsCommand::ExecuteUntilItemsCommand(
    ExecuteUntilItemsCommandParameter* p)
    : ExecuteUntilCommand(p),
      executeCommand(p->executeCommand),
      checkItemsExistenceCommandParameter(*p) {
}

std::shared_ptr<Command> ExecuteUntilItemsCommand::createExecuteCommand() {
    return executeCommand;
}

std::shared_ptr<TCommand<bool>>
ExecuteUntilItemsCommand::createRequestCommand() {
    auto cmd = Factory::createTCommand(&checkItemsExistenceCommandParameter);
    LogicalOperationCommandParameter lp(cmd, true, LogicalOperator::XOR);
    return Factory::createTCommand(&lp);
}
}  // namespace Impl
}  // namespace AutoMacro
