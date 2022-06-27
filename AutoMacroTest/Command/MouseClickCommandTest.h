#pragma once
#include "CppUnitTest.h"

namespace AutoMacro {
namespace Command {
TEST_CLASS(MouseClickCommandTest) {
 public:
    TEST_METHOD(TestSingleClick);
    TEST_METHOD(TestMultipleClick);
    TEST_METHOD(TestMouseMoveAndClick);
};
}  // namespace Command
}  // namespace AutoMacro
