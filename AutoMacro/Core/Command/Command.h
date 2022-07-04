#pragma once
#include "AutoMacro/Core/Core/pch.h"

namespace AutoMacro {
class DLL_EXPORTS Command {
 public:
    virtual void execute() = 0;
};
}  // namespace AutoMacro
