#include "AutoMacro/Command/Command/Command/Commands.h"

namespace AutoMacro {
namespace Impl {
Commands::Commands(std::vector<std::shared_ptr<Command>> commands)
    : commands_(commands) {
}

void Commands::execute() {
    for (const auto& cmd : commands_) {
        cmd->execute();
    }
}
}  // namespace Impl
}  // namespace AutoMacro
