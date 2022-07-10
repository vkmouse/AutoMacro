#pragma once
#include <memory>

#include "AutoMacro/Core/Core/pch.h"
#include "AutoMacro/Core/Command/Command.h"

namespace AutoMacro {
template<class T>
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    std::shared_ptr<TCommand<T>> command);
}  // namespace AutoMacro
