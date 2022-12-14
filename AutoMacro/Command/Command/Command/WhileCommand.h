#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Parameter/WhileCommandParameter.h"

namespace AutoMacro {
class WhileCommand : public TCommand<void> {
 public:
    DLL_EXPORTS explicit WhileCommand(WhileCommandParameter* p);

    DLL_EXPORTS virtual void execute();

 protected:
    WhileCommand();

    void setExecuteCommand(std::shared_ptr<Command> command);
    void setRequestCommand(std::shared_ptr<TCommand<bool>> command);

 private:
    std::shared_ptr<Command> executeCommand_;
    std::shared_ptr<TCommand<bool>> requestCommand_;
};
}  // namespace AutoMacro
