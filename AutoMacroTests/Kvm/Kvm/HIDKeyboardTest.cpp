#include <memory>

#include "AutoMacro/Kvm/Kvm.h"
#include "AutoMacroTests/KeyboardTest.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace KvmTest {
TEST_CLASS(HIDKeyboardTest), public KeyboardTest {
 public:
    HIDKeyboardTest() : KeyboardTest(1) {}

    TEST_METHOD_INITIALIZE(TestMethodInitialize) {
        KeyboardTest::TestMethodInitialize();
    }

    TEST_METHOD_CLEANUP(TestMethodCleanup) {
        KeyboardTest::TestMethodCleanup();
    }

    TEST_METHOD(TestPressAndReleaseAlphabetKey) {
        KeyboardTest::TestPressAndReleaseAlphabetKey();
    }

    TEST_METHOD(TestPressAndReleaseNumericKeys) {
        KeyboardTest::TestPressAndReleaseNumericKeys();
    }

    TEST_METHOD(TestPressAndReleaseOtherTypingKeys) {
        KeyboardTest::TestPressAndReleaseOtherTypingKeys();
    }

    TEST_METHOD(TestPressAndReleaseFuntionKeys) {
        KeyboardTest::TestPressAndReleaseFuntionKeys();
    }

    TEST_METHOD(TestPressAndReleaseKeypadKeys) {
        KeyboardTest::TestPressAndReleaseKeypadKeys();
    }

    TEST_METHOD(TestPressAndReleaseNavigationKeys) {
        KeyboardTest::TestPressAndReleaseNavigationKeys();
    }

    TEST_METHOD(TestPressAndReleaseControlKeys) {
        KeyboardTest::TestPressAndReleaseControlKeys();
    }

    TEST_METHOD(TestKeyboardReleaseAllKeys) {
        KeyboardTest::TestKeyboardReleaseAllKeys();
    }

    TEST_METHOD(TestKeyboardToggleKey) {
        KeyboardTest::TestKeyboardToggleKey();
    }

 protected:
    virtual std::shared_ptr<Keyboard> createKeyboard() {
        return Factory::createHIDKeyboard();
    }
};
}  // namespace KvmTest
}  // namespace AutoMacro
