#include "AutoMacro/Command/Command/Factory/WhileCommandFactory.h"

#include <memory>

#include "AutoMacro/Command/Command/Command/WhileCommand.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Command> createCommand(WhileCommandParameter* p) {
    auto command = createTCommand(p);
    return createCommand(command);
}

std::shared_ptr<TCommand<void>> createTCommand(
        WhileCommandParameter* p) {
    return std::make_shared<WhileCommand>(p);
}
}  // namespace Factory
}  // namespace AutoMacro
