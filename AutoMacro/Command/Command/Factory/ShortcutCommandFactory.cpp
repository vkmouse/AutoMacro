#include "AutoMacro/Command/Command/Factory/ShortcutCommandFactory.h"

#include <memory>

#include "AutoMacro/Command/Command/Parameter/ShortcutCommandParameter.h"
#include "AutoMacro/Command/Command/Command/ShortcutCommand.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Command> createCommand(ShortcutCommandParameter* p) {
    auto command = createTCommand(p);
    return createCommand(command);
}

std::shared_ptr<TCommand<void>> createTCommand(ShortcutCommandParameter* p) {
    return std::make_shared<Impl::ShortcutCommand>(p);
}
}  // namespace Factory
}  // namespace AutoMacro
