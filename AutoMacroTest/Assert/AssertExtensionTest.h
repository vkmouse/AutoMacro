#pragma once
#include "CppUnitTest.h"

namespace AutoMacro {
TEST_CLASS(AssertExtensionTest) {
 public:
    TEST_METHOD(TestImageAreEqual);
    TEST_METHOD(TestImageAreNotEqual);
};
}  // namespace AutoMacro
