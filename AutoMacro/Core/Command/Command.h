#pragma once
#include "AutoMacro/Core/Core/pch.h"

namespace AutoMacro {
class DLL_EXPORTS Command {
 public:
     virtual void execute() = 0;
};

template<typename T>
class DLL_EXPORTS TCommand {
 public:
     virtual T execute() = 0;
};
}  // namespace AutoMacro
