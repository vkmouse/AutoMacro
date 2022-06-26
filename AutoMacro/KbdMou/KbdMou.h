#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Keyboard> createHIDKeyboard();
DLL_EXPORTS std::shared_ptr<Keyboard> createMockKeyboard();
DLL_EXPORTS std::shared_ptr<Mouse> createHIDMouse();
DLL_EXPORTS std::shared_ptr<Mouse> createMockMouse();
}  // namespace Factory
}  // namespace AutoMacro
