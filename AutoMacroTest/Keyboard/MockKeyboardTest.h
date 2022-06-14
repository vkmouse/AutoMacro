#pragma once
#include "CppUnitTest.h"

namespace AutoMacro {
TEST_CLASS(MockKeyboardTest) {
 public:
    TEST_CLASS_INITIALIZE(initialize);
    TEST_CLASS_CLEANUP(cleanup);
    TEST_METHOD(TestMockKeyboardPressAndReleaseKey);
    TEST_METHOD(TestMockKeyboardReleaseAllKeys);
    TEST_METHOD(TestMockKeyboardToggleKey);
};
}  // namespace AutoMacro
