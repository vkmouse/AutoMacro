#include "AutoMacro/Command/Command/Command/ExecuteUntilItemCommand.h"

#include "AutoMacro/Command/Command/Factory/CheckItemExistenceCommandFactory.h"
#include "AutoMacro/Command/Command/Factory/LogicalOperationCommandFactory.h"
#include "AutoMacro/Command/Command/Parameter/ExecuteUntilItemCommandParameter.h"

namespace AutoMacro {
namespace Impl {
ExecuteUntilItemCommand::ExecuteUntilItemCommand(
    ExecuteUntilItemCommandParameter* p)
    : ExecuteUntilCommand(p),
      executeCommand(p->executeCommand),
      checkItemExistenceCommandParameter(*p) {
}

std::shared_ptr<Command> ExecuteUntilItemCommand::createExecuteCommand() {
    return executeCommand;
}

std::shared_ptr<TCommand<bool>>
ExecuteUntilItemCommand::createRequestCommand() {
    auto cmd = Factory::createTCommand(&checkItemExistenceCommandParameter);
    LogicalOperationCommandParameter lp(cmd, true, LogicalOperator::XOR);
    return Factory::createTCommand(&lp);
}
}  // namespace Impl
}  // namespace AutoMacro
