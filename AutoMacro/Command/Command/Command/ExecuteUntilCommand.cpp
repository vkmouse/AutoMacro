#include "AutoMacro/Command/Command/Command/ExecuteUntilCommand.h"

#include "AutoMacro/Command/Command/Factory/CommandsFactory.h"
#include "AutoMacro/Command/Command/Factory/ComparisonOperationCommandFactory.h"
#include "AutoMacro/Command/Command/Factory/CounterCommandFactory.h"
#include "AutoMacro/Command/Command/Factory/LogicalOperationCommandFactory.h"

namespace AutoMacro {
namespace Impl {
ExecuteUntilCommand::ExecuteUntilCommand(ExecuteUntilCommandParameter* p)
    : useLoopCounter(p->useLoopCounter), numLoops(p->numLoops) {
}

void ExecuteUntilCommand::execute() {
    auto executeCommand = createExecuteCommand();
    auto requestCommand = createRequestCommand();
    int current = 0;
    if (useLoopCounter) {
        CounterCommandParameter cp(&current);
        auto ccmd = Factory::createCommand(&cp);
        executeCommand = Factory::createCommand({ executeCommand, ccmd });

        ComparisonOperationCommandParameter cop(
            current, numLoops, ComparisonOperator::LESS_THAN);
        auto cocmd = Factory::createTCommand(&cop);
        LogicalOperationCommandParameter lop(
            { cocmd, requestCommand }, LogicalOperator::AND);
        requestCommand = Factory::createTCommand(&lop);
    }
    setExecuteCommand(executeCommand);
    setRequestCommand(requestCommand);
    WhileCommand::execute();
}
}  // namespace Impl
}  // namespace AutoMacro
