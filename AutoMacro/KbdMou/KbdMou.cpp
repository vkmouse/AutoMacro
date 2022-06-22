#include "AutoMacro/KbdMou/KbdMou.h"

#include <memory>

#include "AutoMacro/KbdMou/KbdMou/HIDKeyboard.h"
#include "AutoMacro/KbdMou/KbdMou/MockKeyboard.h"
#include "AutoMacro/KbdMou/KbdMou/MockMouse.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Keyboard> createHIDKeyboard() {
    return std::make_shared<Impl::HIDKeyboard>();
}

std::shared_ptr<Keyboard> createMockKeyboard() {
    return std::make_shared<Impl::MockKeyboard>();
}

std::shared_ptr<Mouse> createMockMouse() {
    return std::make_shared<Impl::MockMouse>();
}
}  // namespace Factory
}  // namespace AutoMacro
