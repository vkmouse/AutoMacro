#include "AutoMacro/Command/Command/Command/WhileCommand.h"

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
