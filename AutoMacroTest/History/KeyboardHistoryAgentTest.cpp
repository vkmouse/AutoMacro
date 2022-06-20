#include "AutoMacroTest/History/KeyboardHistoryAgentTest.h"

#include "CppUnitTest.h"
#include <AutoMacro/History/History.h>
#include <AutoMacro/Keyboard/Keyboard.h>

namespace AutoMacro {
namespace History {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

void KeyboardHistoryAgentTest::TestKeyboardHistoryAgent() {
    Histories histories;
    auto keyboard = Factory::createMockKeyboard();
    keyboard = Factory::addHistoryAgent(keyboard, &histories);

    keyboard->pressKey(KeyCode::KEY_A);
    Assert::IsTrue(histories.back().equals("pressKey", KeyCode::KEY_A));

    keyboard->releaseKey(KeyCode::KEY_B);
    Assert::IsTrue(histories.back().equals("releaseKey", KeyCode::KEY_B));

    keyboard->releaseAllKeys();
    Assert::IsTrue(histories.back().equals("releaseAllKeys"));
}
}  // namespace History
}  // namespace AutoMacro
