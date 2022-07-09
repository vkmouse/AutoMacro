#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Kvm/Command/Command.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Delay> createActualDelay();
DLL_EXPORTS std::shared_ptr<Keyboard> createHIDKeyboard();
DLL_EXPORTS std::shared_ptr<Mouse> createHIDMouse();
DLL_EXPORTS std::shared_ptr<VideoCapture> createDesktopCapture();
}  // namespace Factory
}  // namespace AutoMacro
