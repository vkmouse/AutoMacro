#pragma once
#include <memory>

#include "AutoMacro/Core/Kvm/Mouse.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Mouse> createMockMouse();
}  // namespace Factory
}  // namespace AutoMacro
