#pragma once
#include "CppUnitTest.h"

namespace AutoMacro {
TEST_CLASS(MockKeyboardTest) {
 public:
    TEST_METHOD(TestMockKeyboardPressAndReleaseKey);
    TEST_METHOD(TestMockKeyboardReleaseAllKeys);
    TEST_METHOD(TestMockKeyboardToggleKey);
};
}  // namespace AutoMacro
