#include "AutoMacroTests/KeyboardTest.h"

#include <memory>

#include "AutoMacro/Kvm/Kvm.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace KvmTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

void KeyboardTest::TestMethodInitialize() {
    if (keyboard == nullptr) {
        keyboard = createKeyboard();
    }
    setLocks(false, false, false);
}

void KeyboardTest::TestMethodCleanup() {
    setLocks(true, false, false);
}

void KeyboardTest::TestPressAndReleaseAlphabetKey() {
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_A);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_B);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_C);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_D);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_E);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_G);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_H);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_I);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_J);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_K);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_L);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_M);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_N);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_O);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_P);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_Q);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_R);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_S);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_T);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_U);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_V);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_W);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_X);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_Y);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_Z);
}

void KeyboardTest::TestPressAndReleaseNumericKeys() {
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_0);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_1);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_2);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_3);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_4);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_5);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_6);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_7);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_8);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_9);
}

void KeyboardTest::TestPressAndReleaseOtherTypingKeys() {
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_GRAVE);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_MINUS);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_EQUAL);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_BACKSPACE);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_TAB);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_LEFTBRACE);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_RIGHTBRACE);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_BACKSLASH);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_CAPSLOCK);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_SEMICOLON);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_APOSTROPHE);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_ENTER);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_LSHIFT);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_COMMA);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_DOT);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_SLASH);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_RSHIFT);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_SPACE);
}

void KeyboardTest::TestPressAndReleaseFuntionKeys() {
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F1);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F2);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F3);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F4);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F5);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F6);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F7);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F8);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F9);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F10);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F11);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F12);
}

void KeyboardTest::TestPressAndReleaseKeypadKeys() {
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_NUMLOCK);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KPSLASH);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KPASTERISK);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KPMINUS);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KPPLUS);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KPENTER);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KP1);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KP2);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KP3);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KP4);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KP5);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KP6);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KP7);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KP8);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KP9);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KP0);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KPDOT);
}

void KeyboardTest::TestPressAndReleaseNavigationKeys() {
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_INSERT);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_DELETE);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_HOME);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_END);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_PAGEUP);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_PAGEDOWN);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_UP);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_DOWN);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_LEFT);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_RIGHT);
}

void KeyboardTest::TestPressAndReleaseControlKeys() {
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_ESC);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_SYSRQ);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_SCROLLLOCK);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_PAUSE);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_LCTRL);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_LMETA);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_LALT);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_RALT);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_RMETA);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_COMPOSE);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_RCTRL);
}

void KeyboardTest::TestKeyboardReleaseAllKeys() {
    Assert::IsFalse(keyboard->isKeyPressed(KeyCode::KEY_A));
    Assert::IsFalse(keyboard->isKeyPressed(KeyCode::KEY_F1));
    Assert::IsFalse(keyboard->isKeyPressed(KeyCode::KEY_ENTER));

    keyboard->pressKey(KeyCode::KEY_A);
    keyboard->pressKey(KeyCode::KEY_F1);
    keyboard->pressKey(KeyCode::KEY_ENTER);
    Assert::IsTrue(keyboard->isKeyPressed(KeyCode::KEY_A));
    Assert::IsTrue(keyboard->isKeyPressed(KeyCode::KEY_F1));
    Assert::IsTrue(keyboard->isKeyPressed(KeyCode::KEY_ENTER));

    keyboard->releaseAllKeys();
    Assert::IsFalse(keyboard->isKeyPressed(KeyCode::KEY_A));
    Assert::IsFalse(keyboard->isKeyPressed(KeyCode::KEY_F1));
    Assert::IsFalse(keyboard->isKeyPressed(KeyCode::KEY_ENTER));
}

void KeyboardTest::TestKeyboardToggleKey() {
    Assert::IsFalse(keyboard->isKeyToggled(KeyCode::KEY_NUMLOCK));
    Assert::IsFalse(keyboard->isKeyToggled(KeyCode::KEY_CAPSLOCK));
    Assert::IsFalse(keyboard->isKeyToggled(KeyCode::KEY_SCROLLLOCK));

    keyboard->pressKey(KeyCode::KEY_NUMLOCK);
    keyboard->pressKey(KeyCode::KEY_CAPSLOCK);
    keyboard->pressKey(KeyCode::KEY_SCROLLLOCK);
    keyboard->releaseAllKeys();
    Assert::IsTrue(keyboard->isKeyToggled(KeyCode::KEY_NUMLOCK));
    Assert::IsTrue(keyboard->isKeyToggled(KeyCode::KEY_CAPSLOCK));
    Assert::IsTrue(keyboard->isKeyToggled(KeyCode::KEY_SCROLLLOCK));

    keyboard->pressKey(KeyCode::KEY_NUMLOCK);
    keyboard->pressKey(KeyCode::KEY_CAPSLOCK);
    keyboard->pressKey(KeyCode::KEY_SCROLLLOCK);
    keyboard->releaseAllKeys();
    Assert::IsFalse(keyboard->isKeyToggled(KeyCode::KEY_NUMLOCK));
    Assert::IsFalse(keyboard->isKeyToggled(KeyCode::KEY_CAPSLOCK));
    Assert::IsFalse(keyboard->isKeyToggled(KeyCode::KEY_SCROLLLOCK));
}

void KeyboardTest::TestPressAndReleaseKey(
    std::shared_ptr<Keyboard> keyboard,
    KeyCode key) {
    Assert::IsFalse(keyboard->isKeyPressed(key));
    keyboard->pressKey(key);
    Assert::IsTrue(keyboard->isKeyPressed(key));
    keyboard->releaseKey(key);
    Assert::IsFalse(keyboard->isKeyPressed(key));
}

void KeyboardTest::setLocks(bool numLock, bool capsLock, bool scrollLock) {
    if (keyboard->isKeyToggled(KeyCode::KEY_NUMLOCK) != numLock) {
        keyboard->pressKey(KeyCode::KEY_NUMLOCK);
        keyboard->releaseKey(KeyCode::KEY_NUMLOCK);
    }
    if (keyboard->isKeyToggled(KeyCode::KEY_CAPSLOCK) != capsLock) {
        keyboard->pressKey(KeyCode::KEY_CAPSLOCK);
        keyboard->releaseKey(KeyCode::KEY_CAPSLOCK);
    }
    if (keyboard->isKeyToggled(KeyCode::KEY_SCROLLLOCK) != scrollLock) {
        keyboard->pressKey(KeyCode::KEY_SCROLLLOCK);
        keyboard->releaseKey(KeyCode::KEY_SCROLLLOCK);
    }
}
}  // namespace KvmTest
}  // namespace AutoMacro
