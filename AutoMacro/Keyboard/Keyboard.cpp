#include "AutoMacro/Keyboard/Keyboard.h"

#include "AutoMacro/Keyboard/MockKeyboard.h"

namespace AutoMacro {
namespace Factory {
Keyboard* createMockKeyboard() {
    return new Impl::MockKeyboard();
}
}  // namespace Factory
}  // namespace AutoMacro
