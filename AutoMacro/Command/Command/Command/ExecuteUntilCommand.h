#pragma once
#include <memory>

#include "AutoMacro/Command/Command/Command/WhileCommand.h"
#include "AutoMacro/Command/Command/Parameter/ExecuteUntilCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class ExecuteUntilCommand : public WhileCommand {
 public:
    explicit ExecuteUntilCommand(ExecuteUntilCommandParameter* p);

    virtual void execute();

 protected:
    virtual std::shared_ptr<Command> createExecuteCommand() = 0;
    virtual std::shared_ptr<TCommand<bool>> createRequestCommand() = 0;

 private:
    bool useLoopCounter;
    int numLoops;
};
}  // namespace Impl
}  // namespace AutoMacro
