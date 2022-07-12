#include "AutoMacro/Command/Command/Command/ExecuteUntilItemsCommand.h"

#include "AutoMacro/Command/Command/Factory/CheckItemsExistenceCommandFactory.h"
#include "AutoMacro/Command/Command/Factory/LogicalOperationCommandFactory.h"
#include "AutoMacro/Command/Command/Parameter/ExecuteUntilItemsCommandParameter.h"

namespace AutoMacro {
namespace Impl {
ExecuteUntilItemsCommand::ExecuteUntilItemsCommand(
        ExecuteUntilItemsCommandParameter* p) {
    setExecuteCommand(p->executeCommand);

    CheckItemsExistenceCommandParameter* cp = p;
    LogicalOperationCommandParameter lp(
        Factory::createTCommand(cp), true, LogicalOperator::XOR);
    auto requestCommand = Factory::createTCommand(&lp);
    setRequestCommand(requestCommand);
}
}  // namespace Impl
}  // namespace AutoMacro
