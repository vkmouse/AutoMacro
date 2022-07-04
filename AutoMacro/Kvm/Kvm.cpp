#include "AutoMacro/Kvm/Kvm.h"

#include <memory>

#include "AutoMacro/Kvm/Command/DesktopSwitchCommand.h"
#include "AutoMacro/Kvm/Command/DesktopSwitchCommandParameter.h"
#include "AutoMacro/Kvm/Command/MouseClickCommand.h"
#include "AutoMacro/Kvm/Command/MouseClickCommandParameter.h"
#include "AutoMacro/Kvm/Command/SendKeyCommand.h"
#include "AutoMacro/Kvm/Command/SendKeyCommandParameter.h"
#include "AutoMacro/Kvm/Command/ShortCutCommand.h"
#include "AutoMacro/Kvm/Command/ShortCutCommandParameter.h"
#include "AutoMacro/Kvm/Kvm/ActualDelay.h"
#include "AutoMacro/Kvm/Kvm/DesktopCapture.h"
#include "AutoMacro/Kvm/Kvm/HIDKeyboard.h"
#include "AutoMacro/Kvm/Kvm/HIDMouse.h"
#include "AutoMacro/Kvm/Kvm/MockKeyboard.h"
#include "AutoMacro/Kvm/Kvm/MockMouse.h"
#include "AutoMacro/Kvm/Kvm/MockVideoCapture.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Delay> createActualDelay() {
    return std::make_shared<Impl::ActualDelay>();
}

std::shared_ptr<Keyboard> createHIDKeyboard() {
    return std::make_shared<Impl::HIDKeyboard>();
}

std::shared_ptr<Keyboard> createMockKeyboard() {
    return std::make_shared<Impl::MockKeyboard>();
}

std::shared_ptr<Mouse> createHIDMouse() {
    return std::make_shared<Impl::HIDMouse>();
}

std::shared_ptr<Mouse> createMockMouse() {
    return std::make_shared<Impl::MockMouse>();
}

std::shared_ptr<VideoCapture> createDesktopCapture() {
    return std::make_shared<Impl::DesktopCapture>();
}

std::shared_ptr<VideoCapture> createMockVideoCapture() {
    return std::make_shared<Impl::MockVideoCapture>();
}

std::shared_ptr<Command> createCommand(
        DesktopSwitchCommandParameter* parameter) {
    return std::make_shared<Impl::DesktopSwitchCommand>(parameter);
}

std::shared_ptr<Command> createCommand(
        SendKeyCommandParameter* parameter) {
    return std::make_shared<Impl::SendKeyCommand>(parameter);
}

std::shared_ptr<Command> createCommand(
        ShortcutCommandParameter* parameter) {
    return std::make_shared<Impl::ShortcutCommand>(parameter);
}

std::shared_ptr<Command> createCommand(
        MouseClickCommandParameter* parameter) {
    return std::make_shared<Impl::MouseClickCommand>(parameter);
}
}  // namespace Factory
}  // namespace AutoMacro
