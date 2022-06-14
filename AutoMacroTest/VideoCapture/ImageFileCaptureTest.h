#pragma once
#include "CppUnitTest.h"

namespace AutoMacro {
TEST_CLASS(ImageFileCaptureTest) {
 public:
    TEST_METHOD(TestTakeSnapshot);
    TEST_METHOD(TestCycleImages);
};
}  // namespace AutoMacro
