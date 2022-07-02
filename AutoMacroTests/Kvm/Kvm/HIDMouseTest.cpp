#include <Windows.h>
#include <memory>

#include "AutoMacro/Kvm/Kvm.h"
#include "AutoMacroTests/Kvm/Kvm/MouseTest.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace KvmTest {
TEST_CLASS(HIDMouseTest), public MouseTest {
 public:
    HIDMouseTest() : MouseTest(3) {}

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
}  // namespace KvmTest
}  // namespace AutoMacro
