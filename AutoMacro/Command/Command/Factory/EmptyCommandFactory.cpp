#include "AutoMacro/Command/Command/Factory/EmptyCommandFactory.h"

#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Command/EmptyCommand.h"

namespace AutoMacro {
namespace Factory {
template<>
DLL_EXPORTS std::shared_ptr<TCommand<void>> createTCommand() {
    return std::make_shared<Impl::EmptyCommand<void>>();
}

template<>
DLL_EXPORTS std::shared_ptr<TCommand<bool>> createTCommand() {
    return std::make_shared<Impl::EmptyCommand<bool>>();
}

std::shared_ptr<Command> createCommand() {
    auto command = createTCommand<void>();
    return createCommand(command);
}
}  // namespace Factory
}  // namespace AutoMacro
