#pragma once
#include "CppUnitTest.h"

namespace AutoMacro {
namespace Detection {
TEST_CLASS(DetectionPreprocessorTest) {
 public:
    TEST_METHOD(TestBGRConverterProcessor);
    TEST_METHOD(TestCroppingProcessor);
    TEST_METHOD(TestMixedProcessor);
};
}  // namespace Detection
}  // namespace AutoMacro
