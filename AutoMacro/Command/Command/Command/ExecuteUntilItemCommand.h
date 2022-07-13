#pragma once
#include <memory>

#include "AutoMacro/Command/Command/Command/ExecuteUntilCommand.h"
#include "AutoMacro/Command/Command/Parameter/CheckItemExistenceCommandParameter.h"
#include "AutoMacro/Command/Command/Parameter/ExecuteUntilItemCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class ExecuteUntilItemCommand : public ExecuteUntilCommand {
 public:
    explicit ExecuteUntilItemCommand(ExecuteUntilItemCommandParameter* p);

 protected:
    virtual std::shared_ptr<Command> createExecuteCommand();
    virtual std::shared_ptr<TCommand<bool>> createRequestCommand();

 private:
    std::shared_ptr<Command> executeCommand;
    CheckItemExistenceCommandParameter checkItemExistenceCommandParameter;
};
}  // namespace Impl
}  // namespace AutoMacro
