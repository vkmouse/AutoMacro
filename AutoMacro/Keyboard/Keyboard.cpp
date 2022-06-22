#include "AutoMacro/Keyboard/Keyboard.h"

#include "AutoMacro/Keyboard/Keyboard/MockKeyboard.h"
#include "AutoMacro/Keyboard/Keyboard/HIDKeyboard.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Keyboard> createMockKeyboard() {
    return std::make_shared<Impl::MockKeyboard>();
}

std::shared_ptr<Keyboard> createHIDKeyboard() {
    return std::make_shared<Impl::HIDKeyboard>();
}
}  // namespace Factory
}  // namespace AutoMacro
