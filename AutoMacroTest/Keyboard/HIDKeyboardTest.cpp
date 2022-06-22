#include "AutoMacroTest/Keyboard/HIDKeyboardTest.h"

#include <memory>

#include <AutoMacro/Keyboard/Keyboard.h>

namespace AutoMacro {
void HIDKeyboardTest::TestHIDKeyboardPressAndReleaseKey() {
    TestKeyboardPressAndReleaseKey();
}

void HIDKeyboardTest::TestHIDKeyboardReleaseAllKeys() {
    TestKeyboardReleaseAllKeys();
}

void HIDKeyboardTest::TestHIDKeyboardToggleKey() {
    TestKeyboardToggleKey();
}

std::shared_ptr<Keyboard> HIDKeyboardTest::createKeyboard() {
    return Factory::createHIDKeyboard();
}
}  // namespace AutoMacro
