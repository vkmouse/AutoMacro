#pragma once
#include "CppUnitTest.h"

namespace AutoMacro {
TEST_CLASS(VideoCapturePostProcessorTest) {
 public:
    TEST_METHOD(TestBGRConverterProcessor);
    TEST_METHOD(TestCroppingProcessor);
    TEST_METHOD(TestMixedProcessor);
};
}  // namespace AutoMacro
