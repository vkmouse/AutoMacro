#pragma once
#include "CppUnitTest.h"

namespace AutoMacro {
namespace Detection {
TEST_CLASS(TemplateBasedDetectorTest) {
 public:
    TEST_METHOD(TestCreateTempateBasedDetector);
    TEST_METHOD(TestNoTemplateFailed);
    TEST_METHOD(TestInitializationFailed);
    TEST_METHOD(TestTempateBasedDetector);
    TEST_METHOD(TestNotExistTemplate);
    TEST_METHOD(TestTempateBasedDetectorWithMask);
    TEST_METHOD(TestMultipleBoxes);
};
}  // namespace Detection
}  // namespace AutoMacro
