#include "AutoMacro/Core/Core.h"

#include <memory>

#include "AutoMacro/Core/Command/Commands.h"
#include "AutoMacro/Core/Command/EmptyCommand.h"
#include "AutoMacro/Core/Kvm/MockDelay.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Delay> createMockDelay() {
    return std::make_shared<Impl::MockDelay>();
}

std::shared_ptr<Command> createCommands() {
    return std::make_shared<Impl::EmptyCommand>();
}

std::shared_ptr<Command> createCommands(CommandsParameter* p) {
    return std::make_shared<Impl::Commands>(p);
}
}  // namespace Factory
}  // namespace AutoMacro
