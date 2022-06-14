#include "AutoMacroTest/Keyboard/MockKeyboardTest.h"

#include "CppUnitTest.h"
#include <AutoMacro/Keyboard/Keyboard.h>
#include <AutoMacro/Keyboard/MockKeyboard.h>

namespace AutoMacro {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
using Impl::MockKeyboard;
Keyboard* keyboard;
void assertKeyIsPressed(KeyCode key) {
    Assert::AreEqual(true, MockKeyboard::isKeyPressed(key));
}

void assertKeyIsReleased(KeyCode key) {
    Assert::AreEqual(false, MockKeyboard::isKeyPressed(key));
}

void assertKeyIsToggled(KeyCode key) {
    Assert::AreEqual(true, MockKeyboard::isKeyToggled(key));
}

void assertKeyIsNotToggled(KeyCode key) {
    Assert::AreEqual(false, MockKeyboard::isKeyToggled(key));
}
}  // namespace

void __stdcall MockKeyboardTest::initialize() {
    keyboard = Factory::createMockKeyboard();
}

void __stdcall MockKeyboardTest::cleanup() {
    delete(keyboard);
}

void MockKeyboardTest::TestMockKeyboardPressAndReleaseKey() {
    assertKeyIsReleased(KeyCode::KEY_A);

    keyboard->pressKey(KeyCode::KEY_A);
    assertKeyIsPressed(KeyCode::KEY_A);

    keyboard->releaseKey(KeyCode::KEY_A);
    assertKeyIsReleased(KeyCode::KEY_A);
}

void MockKeyboardTest::TestMockKeyboardReleaseAllKeys() {
    assertKeyIsReleased(KeyCode::KEY_A);
    assertKeyIsReleased(KeyCode::KEY_F1);
    assertKeyIsReleased(KeyCode::KEY_ENTER);

    keyboard->pressKey(KeyCode::KEY_A);
    keyboard->pressKey(KeyCode::KEY_F1);
    keyboard->pressKey(KeyCode::KEY_ENTER);
    assertKeyIsPressed(KeyCode::KEY_A);
    assertKeyIsPressed(KeyCode::KEY_F1);
    assertKeyIsPressed(KeyCode::KEY_ENTER);

    keyboard->releaseAllKeys();
    assertKeyIsReleased(KeyCode::KEY_A);
    assertKeyIsReleased(KeyCode::KEY_F1);
    assertKeyIsReleased(KeyCode::KEY_ENTER);
}

void MockKeyboardTest::TestMockKeyboardToggleKey() {
    assertKeyIsNotToggled(KeyCode::KEY_NUMLOCK);
    assertKeyIsNotToggled(KeyCode::KEY_CAPSLOCK);
    assertKeyIsNotToggled(KeyCode::KEY_SCROLLLOCK);

    keyboard->pressKey(KeyCode::KEY_NUMLOCK);
    keyboard->pressKey(KeyCode::KEY_CAPSLOCK);
    keyboard->pressKey(KeyCode::KEY_SCROLLLOCK);
    keyboard->releaseAllKeys();
    assertKeyIsToggled(KeyCode::KEY_NUMLOCK);
    assertKeyIsToggled(KeyCode::KEY_CAPSLOCK);
    assertKeyIsToggled(KeyCode::KEY_SCROLLLOCK);

    keyboard->pressKey(KeyCode::KEY_NUMLOCK);
    keyboard->pressKey(KeyCode::KEY_CAPSLOCK);
    keyboard->pressKey(KeyCode::KEY_SCROLLLOCK);
    keyboard->releaseAllKeys();
    assertKeyIsNotToggled(KeyCode::KEY_NUMLOCK);
    assertKeyIsNotToggled(KeyCode::KEY_CAPSLOCK);
    assertKeyIsNotToggled(KeyCode::KEY_SCROLLLOCK);
}
}  // namespace AutoMacro
