#pragma once
#include "CppUnitTest.h"

namespace AutoMacro {
namespace Detection {
TEST_CLASS(DetectionResultsTest) {
 public:
    TEST_METHOD(TestExists);
    TEST_METHOD(TestCountAndWhere);
};
}  // namespace Detection
}  //  namespace AutoMacro
