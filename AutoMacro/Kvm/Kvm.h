#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Kvm/Command/DesktopSwitchCommandParameter.h"
#include "AutoMacro/Kvm/Command/MouseClickCommandParameter.h"
#include "AutoMacro/Kvm/Command/SendKeyCommandParameter.h"
#include "AutoMacro/Kvm/Command/ShortCutCommandParameter.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Delay> createActualDelay();
DLL_EXPORTS std::shared_ptr<Keyboard> createHIDKeyboard();
DLL_EXPORTS std::shared_ptr<Keyboard> createMockKeyboard();
DLL_EXPORTS std::shared_ptr<Mouse> createHIDMouse();
DLL_EXPORTS std::shared_ptr<Mouse> createMockMouse();
DLL_EXPORTS std::shared_ptr<VideoCapture> createDesktopCapture();
DLL_EXPORTS std::shared_ptr<VideoCapture> createMockVideoCapture();

DLL_EXPORTS std::shared_ptr<Command> createCommand(
    DesktopSwitchCommandParameter* parameter);
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    SendKeyCommandParameter* parameter);
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    ShortcutCommandParameter* parameter);
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    MouseClickCommandParameter* parameter);
}  // namespace Factory
}  // namespace AutoMacro
