#include "AutoMacro/Command/Command/Factory/MouseClickCommandFactory.h"

#include <memory>

#include "AutoMacro/Command/Command/Command/MouseClickCommand.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Command> createCommand(MouseClickCommandParameter* p) {
    auto command = createTCommand(p);
    return createCommand(command);
}

std::shared_ptr<TCommand<void>> createTCommand(MouseClickCommandParameter* p) {
    return std::make_shared<Impl::MouseClickCommand>(p);
}
}  // namespace Factory
}  // namespace AutoMacro
