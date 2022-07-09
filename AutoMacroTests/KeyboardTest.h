#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace KvmTest {
class KeyboardTest {
 protected:
    explicit KeyboardTest(int delay) {}

    virtual std::shared_ptr<Keyboard> createKeyboard() = 0;

    void TestMethodInitialize();
    void TestMethodCleanup();

    void TestPressAndReleaseAlphabetKey();
    void TestPressAndReleaseNumericKeys();
    void TestPressAndReleaseOtherTypingKeys();
    void TestPressAndReleaseFuntionKeys();
    void TestPressAndReleaseKeypadKeys();
    void TestPressAndReleaseNavigationKeys();
    void TestPressAndReleaseControlKeys();

    void TestKeyboardReleaseAllKeys();
    void TestKeyboardToggleKey();

 private:
    static void TestPressAndReleaseKey(
        std::shared_ptr<Keyboard> keyboard,
        KeyCode key);

    void setLocks(bool numLock, bool capsLock, bool scrollLock);

    std::shared_ptr<Keyboard> keyboard = nullptr;
};
}  // namespace KvmTest
}  // namespace AutoMacro
