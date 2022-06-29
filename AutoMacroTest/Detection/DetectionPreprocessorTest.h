#pragma once
#include "CppUnitTest.h"

namespace AutoMacro {
namespace Detection {
TEST_CLASS(DetectionPreprocessorTest) {
 public:
    TEST_METHOD(TestBGRConverterProcessor);
    TEST_METHOD(TestCroppingProcessor);
    TEST_METHOD(TestMixedProcessor);
    TEST_METHOD(TestMultipleCroppingProcessor);
};
}  // namespace Detection
}  // namespace AutoMacro
