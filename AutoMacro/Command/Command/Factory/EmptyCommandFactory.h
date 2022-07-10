#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Factory {
template<class T>
DLL_EXPORTS std::shared_ptr<TCommand<T>> createTCommand();
DLL_EXPORTS std::shared_ptr<Command> createCommand();
}  // namespace Factory
}  // namespace AutoMacro
