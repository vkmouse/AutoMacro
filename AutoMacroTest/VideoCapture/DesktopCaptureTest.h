#pragma once
#include "CppUnitTest.h"

namespace AutoMacro {
TEST_CLASS(DesktopCaptureTest) {
 public:
    TEST_METHOD(TestTakeSnapshotWithProcessor);
    TEST_METHOD(TestImageIsValid);
};
}  // namespace AutoMacro
