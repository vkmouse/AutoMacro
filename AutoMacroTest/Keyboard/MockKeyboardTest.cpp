#include "AutoMacroTest/Keyboard/MockKeyboardTest.h"

#include <memory>

#include <AutoMacro/Keyboard/Keyboard.h>

namespace AutoMacro {
void MockKeyboardTest::TestMockKeyboardPressAndReleaseKey() {
    TestKeyboardPressAndReleaseKey();
}

void MockKeyboardTest::TestMockKeyboardReleaseAllKeys() {
    TestKeyboardReleaseAllKeys();
}

void MockKeyboardTest::TestMockKeyboardToggleKey() {
    TestKeyboardToggleKey();
}

std::shared_ptr<Keyboard> MockKeyboardTest::createKeyboard() {
    return Factory::createMockKeyboard();
}
}  // namespace AutoMacro
