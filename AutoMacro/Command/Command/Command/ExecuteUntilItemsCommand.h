#pragma once
#include <memory>

#include "AutoMacro/Command/Command/Command/ExecuteUntilCommand.h"
#include "AutoMacro/Command/Command/Parameter/CheckItemsExistenceCommandParameter.h"
#include "AutoMacro/Command/Command/Parameter/ExecuteUntilItemsCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class ExecuteUntilItemsCommand : public ExecuteUntilCommand {
 public:
    explicit ExecuteUntilItemsCommand(ExecuteUntilItemsCommandParameter* p);

 protected:
    virtual std::shared_ptr<Command> createExecuteCommand();
    virtual std::shared_ptr<TCommand<bool>> createRequestCommand();

 private:
    std::shared_ptr<Command> executeCommand;
    CheckItemsExistenceCommandParameter* checkItemsExistenceCommandParameter;
};
}  // namespace Impl
}  // namespace AutoMacro
