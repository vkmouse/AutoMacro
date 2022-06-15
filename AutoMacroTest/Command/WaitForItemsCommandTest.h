#pragma once
#include "CppUnitTest.h"

namespace AutoMacro {
namespace Command {
TEST_CLASS(WaitForItemsCommandTest) {
 public:
    TEST_METHOD(TestWaitForAllItems);
    TEST_METHOD(TestWaitForAtLeastOneItem);
};
}  // namespace Command
}  // namespace AutoMacro
