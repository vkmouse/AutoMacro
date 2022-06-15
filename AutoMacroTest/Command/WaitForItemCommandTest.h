#pragma once
#include "CppUnitTest.h"

namespace AutoMacro {
namespace Command {
TEST_CLASS(WaitForItemCommandTest) {
 public:
    TEST_METHOD(TestWaitForItemExist);
    TEST_METHOD(TestWaitForItemNotExist);
};
}  // namespace Command
}  // namespace AutoMacro
