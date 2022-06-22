#pragma once
#include "CppUnitTest.h"
#include "AutoMacroTest/KbdMou/KeyboardTest.h"

namespace AutoMacro {
TEST_CLASS(MockKeyboardTest), public KeyboardTest {
 public:
    TEST_METHOD(TestMockKeyboardPressAndReleaseKey);
    TEST_METHOD(TestMockKeyboardReleaseAllKeys);
    TEST_METHOD(TestMockKeyboardToggleKey);

 protected:
    virtual std::shared_ptr<Keyboard> createKeyboard();
};
}  // namespace AutoMacro
