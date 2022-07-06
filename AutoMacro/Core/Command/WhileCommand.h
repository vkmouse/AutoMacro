#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Core/Command/WhileCommandParameter.h"

namespace AutoMacro {
class WhileCommand : public TCommand<void> {
 public:
    explicit WhileCommand(WhileCommandParameter* p);

    virtual void execute();

 private:
    std::shared_ptr<Command> executeCommand_;
    std::shared_ptr<TCommand<bool>> requestCommand_;
};
}  // namespace AutoMacro
