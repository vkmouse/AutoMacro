#pragma once
#include "CppUnitTest.h"

namespace AutoMacro {
namespace Detection {
TEST_CLASS(TemplateBasedDetectorTest) {
 public:
    TEST_METHOD(TestCreateTempateBasedDetector);
    TEST_METHOD(TestTempateBasedDetector);
    TEST_METHOD(TestNotExistTemplate);
    TEST_METHOD(TestTempateBasedDetectorWithMask);
};
}  // namespace Detection
}  // namespace AutoMacro
