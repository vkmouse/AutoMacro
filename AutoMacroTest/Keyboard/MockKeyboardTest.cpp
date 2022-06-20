#include "AutoMacroTest/Keyboard/MockKeyboardTest.h"

#include <memory>

#include "CppUnitTest.h"
#include <AutoMacro/Keyboard/Keyboard.h>

namespace AutoMacro {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
void assertKeyIsPressed(std::shared_ptr<Keyboard> keyboard, KeyCode key) {
    Assert::AreEqual(true, keyboard->isKeyPressed(key));
}

void assertKeyIsReleased(std::shared_ptr<Keyboard> keyboard, KeyCode key) {
    Assert::AreEqual(false, keyboard->isKeyPressed(key));
}

void assertKeyIsToggled(std::shared_ptr<Keyboard> keyboard, KeyCode key) {
    Assert::AreEqual(true, keyboard->isKeyToggled(key));
}

void assertKeyIsNotToggled(std::shared_ptr<Keyboard> keyboard, KeyCode key) {
    Assert::AreEqual(false, keyboard->isKeyToggled(key));
}
}  // namespace

void MockKeyboardTest::TestMockKeyboardPressAndReleaseKey() {
    auto keyboard = Factory::createMockKeyboard();

    assertKeyIsReleased(keyboard, KeyCode::KEY_A);

    keyboard->pressKey(KeyCode::KEY_A);
    assertKeyIsPressed(keyboard, KeyCode::KEY_A);

    keyboard->releaseKey(KeyCode::KEY_A);
    assertKeyIsReleased(keyboard, KeyCode::KEY_A);
}

void MockKeyboardTest::TestMockKeyboardReleaseAllKeys() {
    auto keyboard = Factory::createMockKeyboard();

    assertKeyIsReleased(keyboard, KeyCode::KEY_A);
    assertKeyIsReleased(keyboard, KeyCode::KEY_F1);
    assertKeyIsReleased(keyboard, KeyCode::KEY_ENTER);

    keyboard->pressKey(KeyCode::KEY_A);
    keyboard->pressKey(KeyCode::KEY_F1);
    keyboard->pressKey(KeyCode::KEY_ENTER);
    assertKeyIsPressed(keyboard, KeyCode::KEY_A);
    assertKeyIsPressed(keyboard, KeyCode::KEY_F1);
    assertKeyIsPressed(keyboard, KeyCode::KEY_ENTER);

    keyboard->releaseAllKeys();
    assertKeyIsReleased(keyboard, KeyCode::KEY_A);
    assertKeyIsReleased(keyboard, KeyCode::KEY_F1);
    assertKeyIsReleased(keyboard, KeyCode::KEY_ENTER);
}

void MockKeyboardTest::TestMockKeyboardToggleKey() {
    auto keyboard = Factory::createMockKeyboard();

    assertKeyIsNotToggled(keyboard, KeyCode::KEY_NUMLOCK);
    assertKeyIsNotToggled(keyboard, KeyCode::KEY_CAPSLOCK);
    assertKeyIsNotToggled(keyboard, KeyCode::KEY_SCROLLLOCK);

    keyboard->pressKey(KeyCode::KEY_NUMLOCK);
    keyboard->pressKey(KeyCode::KEY_CAPSLOCK);
    keyboard->pressKey(KeyCode::KEY_SCROLLLOCK);
    keyboard->releaseAllKeys();
    assertKeyIsToggled(keyboard, KeyCode::KEY_NUMLOCK);
    assertKeyIsToggled(keyboard, KeyCode::KEY_CAPSLOCK);
    assertKeyIsToggled(keyboard, KeyCode::KEY_SCROLLLOCK);

    keyboard->pressKey(KeyCode::KEY_NUMLOCK);
    keyboard->pressKey(KeyCode::KEY_CAPSLOCK);
    keyboard->pressKey(KeyCode::KEY_SCROLLLOCK);
    keyboard->releaseAllKeys();
    assertKeyIsNotToggled(keyboard, KeyCode::KEY_NUMLOCK);
    assertKeyIsNotToggled(keyboard, KeyCode::KEY_CAPSLOCK);
    assertKeyIsNotToggled(keyboard, KeyCode::KEY_SCROLLLOCK);
}
}  // namespace AutoMacro
