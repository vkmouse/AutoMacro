#pragma once
#include "AutoMacro/Core/pch.h"

namespace AutoMacro {
namespace Command {
class DLL_EXPORTS Command {
 public:
    virtual void execute() = 0;
};
}  // namespace Command
}  // namespace AutoMacro
