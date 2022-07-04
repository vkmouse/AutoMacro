#include "AutoMacro/Core/Command/Commands.h"

namespace AutoMacro {
namespace Impl {
Commands::Commands(CommandsParameter* p) : Command(p),
    commands_(p->commands) {
}

void Commands::executeCommand() {
    for (const auto& cmd : commands_) {
        cmd->execute();
    }
}
}  // namespace Impl
}  // namespace AutoMacro
