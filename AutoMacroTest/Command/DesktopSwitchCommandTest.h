#pragma once
#include "CppUnitTest.h"

namespace AutoMacro {
namespace Command {
TEST_CLASS(DesktopSwitchCommandTest) {
 public:
    TEST_METHOD_INITIALIZE(methodInitialize);
    TEST_METHOD_CLEANUP(methodCleanup);
    TEST_METHOD(TestDesktopSwitch);
    TEST_METHOD(TestDelayBetweenEachSwitch);
};
}  // namespace Command
}  // namespace AutoMacro
