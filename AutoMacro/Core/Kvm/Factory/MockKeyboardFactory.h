#pragma once
#include <memory>

#include "AutoMacro/Core/Kvm/Keyboard.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Keyboard> createMockKeyboard();
}  // namespace Factory
}  // namespace AutoMacro
