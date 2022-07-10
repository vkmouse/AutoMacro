#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Factory {
template<class T>
DLL_EXPORTS std::shared_ptr<TCommand<T>> createTCommand(
    std::vector<std::shared_ptr<Command>> commands);
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    std::vector<std::shared_ptr<Command>> commands);
}  // namespace Factory
}  // namespace AutoMacro
