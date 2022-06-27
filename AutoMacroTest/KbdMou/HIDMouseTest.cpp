#include <Windows.h>
#include <memory>

#include "AutoMacro/KbdMou/KbdMou.h"
#include "AutoMacroTest/KbdMou/MouseTest.h"
#include "CppUnitTest.h"

namespace AutoMacro {
TEST_CLASS(HIDMouseTest), public MouseTest {
 public:
    HIDMouseTest() : MouseTest(1, 3) {}

    TEST_METHOD_INITIALIZE(TestMethodInitialize) {
        MouseTest::TestMethodInitialize();
    }

    TEST_METHOD(TestMouseButtonDownAndUp) {
        MouseTest::TestMouseButtonDownAndUp();
    }

    TEST_METHOD(TestReleaseAllButtons) {
        MouseTest::TestReleaseAllButtons();
    }

    TEST_METHOD(TestMouseMove) {
        MouseTest::TestMouseMove();
    }

 protected:
    virtual std::shared_ptr<Mouse> createMouse() {
        return Factory::createHIDMouse();
    }
};
}  // namespace AutoMacro
