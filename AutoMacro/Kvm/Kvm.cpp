#include "AutoMacro/Kvm/Kvm.h"

#include <memory>

#include "AutoMacro/Kvm/Kvm/ActualDelay.h"
#include "AutoMacro/Kvm/Kvm/DesktopCapture.h"
#include "AutoMacro/Kvm/Kvm/HIDKeyboard.h"
#include "AutoMacro/Kvm/Kvm/HIDMouse.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Delay> createActualDelay() {
    return std::make_shared<Impl::ActualDelay>();
}

std::shared_ptr<Keyboard> createHIDKeyboard() {
    return std::make_shared<Impl::HIDKeyboard>();
}

std::shared_ptr<Mouse> createHIDMouse() {
    return std::make_shared<Impl::HIDMouse>();
}

std::shared_ptr<VideoCapture> createDesktopCapture() {
    return std::make_shared<Impl::DesktopCapture>();
}
}  // namespace Factory
}  // namespace AutoMacro
