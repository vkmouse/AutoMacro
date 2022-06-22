#pragma once
#include "CppUnitTest.h"
#include "AutoMacroTest/KbdMou/KeyboardTest.h"

namespace AutoMacro {
TEST_CLASS(HIDKeyboardTest), public KeyboardTest {
 public:
    TEST_METHOD(TestHIDKeyboardPressAndReleaseKey);
    TEST_METHOD(TestHIDKeyboardReleaseAllKeys);
    TEST_METHOD(TestHIDKeyboardToggleKey);

 protected:
    virtual std::shared_ptr<Keyboard> createKeyboard();
};
}  // namespace AutoMacro
