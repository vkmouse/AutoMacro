#include "AutoMacro/Command/Command/Command/ExecuteUntilItemCommand.h"

#include "AutoMacro/Command/Command/Factory/CheckItemExistenceCommandFactory.h"
#include "AutoMacro/Command/Command/Factory/LogicalOperationCommandFactory.h"
#include "AutoMacro/Command/Command/Parameter/ExecuteUntilItemCommandParameter.h"

namespace AutoMacro {
namespace Impl {
ExecuteUntilItemCommand::ExecuteUntilItemCommand(
        ExecuteUntilItemCommandParameter* p) {
    setExecuteCommand(p->executeCommand);

    CheckItemExistenceCommandParameter* cp = p;
    LogicalOperationCommandParameter lp(
        Factory::createTCommand(cp), true, LogicalOperator::XOR);
    auto requestCommand = Factory::createTCommand(&lp);
    setRequestCommand(requestCommand);
}
}  // namespace Impl
}  // namespace AutoMacro
