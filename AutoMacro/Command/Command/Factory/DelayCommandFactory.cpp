#include "AutoMacro/Command/Command/Factory/DelayCommandFactory.h"

#include <memory>

#include "AutoMacro/Command/Command/Command/DelayCommand.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Command> createCommand(DelayCommandParameter* p) {
    auto command = createTCommand(p);
    return createCommand(command);
}

std::shared_ptr<TCommand<void>> createTCommand(DelayCommandParameter* p) {
    return std::make_shared<Impl::DelayCommand>(p);
}
}  // namespace Factory
}  // namespace AutoMacro
