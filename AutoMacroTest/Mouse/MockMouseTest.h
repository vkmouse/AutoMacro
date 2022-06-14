#pragma once
#include "CppUnitTest.h"

namespace AutoMacro {
TEST_CLASS(MockMouseTest) {
 public:
    TEST_CLASS_INITIALIZE(initialize);
    TEST_CLASS_CLEANUP(cleanup);
    TEST_METHOD(TestMockMouseDownAndUp);
    TEST_METHOD(TestMockMouseReleaseAllKeys);
    TEST_METHOD(TestMockMouseMove);
};
}  // namespace AutoMacro
