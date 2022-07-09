#include <memory>

#include "AutoMacro/Kvm/Kvm.h"
#include "AutoMacroTests/MouseTest.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace KvmTest {
TEST_CLASS(MockMouseTest), public MouseTest {
 public:
    MockMouseTest() : MouseTest(0) {}

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
        return Factory::createMockMouse();
    }
};
}  // namespace KvmTest
}  // namespace AutoMacro
