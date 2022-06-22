#include "AutoMacroTest/KbdMou/MockKeyboardTest.h"

#include <memory>

#include <AutoMacro/KbdMou/KbdMou.h>

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
