#include "AutoMacro/Core/Command/WhileCommand.h"

#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Core/Command/WhileCommandParameter.h"

namespace AutoMacro {
WhileCommand::WhileCommand(WhileCommandParameter* p)
    : executeCommand_(p->executeCommand),
      requestCommand_(p->requestCommand) {
}

void WhileCommand::execute() {
    while (!requestCommand_->execute()) {
        executeCommand_->execute();
    }
}
}  // namespace AutoMacro
