#include "AutoMacroTest/KbdMou/KeyboardTest.h"

#include <Windows.h>
#include <memory>

#include "CppUnitTest.h"
#include <AutoMacro/KbdMou/KbdMou.h>

namespace AutoMacro {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

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
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_A, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_B, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_C, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_D, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_E, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_G, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_H, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_I, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_J, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_K, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_L, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_M, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_N, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_O, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_P, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_Q, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_R, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_S, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_T, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_U, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_V, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_W, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_X, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_Y, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_Z, delay);
}

void KeyboardTest::TestPressAndReleaseNumericKeys() {
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_0, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_1, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_2, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_3, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_4, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_5, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_6, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_7, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_8, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_9, delay);
}

void KeyboardTest::TestPressAndReleaseOtherTypingKeys() {
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_GRAVE, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_MINUS, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_EQUAL, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_BACKSPACE, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_TAB, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_LEFTBRACE, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_RIGHTBRACE, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_BACKSLASH, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_CAPSLOCK, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_SEMICOLON, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_APOSTROPHE, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_ENTER, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_LSHIFT, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_COMMA, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_DOT, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_SLASH, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_RSHIFT, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_SPACE, delay);
}

void KeyboardTest::TestPressAndReleaseFuntionKeys() {
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F1, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F2, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F3, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F4, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F5, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F6, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F7, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F8, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F9, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F10, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F11, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_F12, delay);
}

void KeyboardTest::TestPressAndReleaseKeypadKeys() {
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_NUMLOCK, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KPSLASH, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KPASTERISK, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KPMINUS, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KPPLUS, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KPENTER, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KP1, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KP2, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KP3, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KP4, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KP5, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KP6, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KP7, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KP8, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KP9, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KP0, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_KPDOT, delay);
}

void KeyboardTest::TestPressAndReleaseNavigationKeys() {
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_INSERT, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_DELETE, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_HOME, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_END, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_PAGEUP, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_PAGEDOWN, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_UP, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_DOWN, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_LEFT, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_RIGHT, delay);
}

void KeyboardTest::TestPressAndReleaseControlKeys() {
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_ESC, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_SYSRQ, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_SCROLLLOCK, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_PAUSE, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_LCTRL, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_LMETA, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_LALT, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_RALT, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_RMETA, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_COMPOSE, delay);
    TestPressAndReleaseKey(keyboard, KeyCode::KEY_RCTRL, delay);
}

void KeyboardTest::TestKeyboardReleaseAllKeys() {
    Assert::IsFalse(keyboard->isKeyPressed(KeyCode::KEY_A));
    Assert::IsFalse(keyboard->isKeyPressed(KeyCode::KEY_F1));
    Assert::IsFalse(keyboard->isKeyPressed(KeyCode::KEY_ENTER));

    keyboard->pressKey(KeyCode::KEY_A);
    keyboard->pressKey(KeyCode::KEY_F1);
    keyboard->pressKey(KeyCode::KEY_ENTER);
    Sleep(delay);
    Assert::IsTrue(keyboard->isKeyPressed(KeyCode::KEY_A));
    Assert::IsTrue(keyboard->isKeyPressed(KeyCode::KEY_F1));
    Assert::IsTrue(keyboard->isKeyPressed(KeyCode::KEY_ENTER));

    keyboard->releaseAllKeys();
    Sleep(delay);
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
    Sleep(delay);
    Assert::IsTrue(keyboard->isKeyToggled(KeyCode::KEY_NUMLOCK));
    Assert::IsTrue(keyboard->isKeyToggled(KeyCode::KEY_CAPSLOCK));
    Assert::IsTrue(keyboard->isKeyToggled(KeyCode::KEY_SCROLLLOCK));

    keyboard->pressKey(KeyCode::KEY_NUMLOCK);
    keyboard->pressKey(KeyCode::KEY_CAPSLOCK);
    keyboard->pressKey(KeyCode::KEY_SCROLLLOCK);
    keyboard->releaseAllKeys();
    Sleep(delay);
    Assert::IsFalse(keyboard->isKeyToggled(KeyCode::KEY_NUMLOCK));
    Assert::IsFalse(keyboard->isKeyToggled(KeyCode::KEY_CAPSLOCK));
    Assert::IsFalse(keyboard->isKeyToggled(KeyCode::KEY_SCROLLLOCK));
}

void KeyboardTest::TestPressAndReleaseKey(
    std::shared_ptr<Keyboard> keyboard,
    KeyCode key,
    int delay) {
    Assert::IsFalse(keyboard->isKeyPressed(key));
    keyboard->pressKey(key);
    Sleep(delay);
    Assert::IsTrue(keyboard->isKeyPressed(key));
    keyboard->releaseKey(key);
    Sleep(delay);
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
    Sleep(delay);
}
}  // namespace AutoMacro
