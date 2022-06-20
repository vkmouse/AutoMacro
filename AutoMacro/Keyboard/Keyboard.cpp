#include "AutoMacro/Keyboard/Keyboard.h"

#include "AutoMacro/Keyboard/Keyboard/MockKeyboard.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Keyboard> createMockKeyboard() {
    return std::make_shared<Impl::MockKeyboard>();
}
}  // namespace Factory
}  // namespace AutoMacro
