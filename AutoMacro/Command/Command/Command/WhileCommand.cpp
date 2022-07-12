#include "AutoMacro/Command/Command/Command/WhileCommand.h"

namespace AutoMacro {
WhileCommand::WhileCommand(WhileCommandParameter* p)
    : executeCommand_(p->executeCommand),
      requestCommand_(p->requestCommand) {
}

void WhileCommand::execute() {
    while (requestCommand_->execute()) {
        executeCommand_->execute();
    }
}

WhileCommand::WhileCommand()
    : executeCommand_(nullptr), requestCommand_(nullptr) {
}

void WhileCommand::setExecuteCommand(std::shared_ptr<Command> command) {
    executeCommand_ = command;
}

void WhileCommand::setRequestCommand(std::shared_ptr<TCommand<bool>> command) {
    requestCommand_ = command;
}
}  // namespace AutoMacro
