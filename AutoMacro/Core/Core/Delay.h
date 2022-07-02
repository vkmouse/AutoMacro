#pragma once
#include "AutoMacro/Core/Core/pch.h"

namespace AutoMacro {
class DLL_EXPORTS Delay {
 public:
    virtual void execute(int ms) = 0;
};
}  // namespace AutoMacro
