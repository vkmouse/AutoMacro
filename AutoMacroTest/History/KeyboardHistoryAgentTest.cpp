#include "AutoMacroTest/History/KeyboardHistoryAgentTest.h"

#include "CppUnitTest.h"
#include <AutoMacro/History/History.h>
#include <AutoMacro/Keyboard/Keyboard.h>
#include "AutoMacroTest/History/HistoryAssert.h"

namespace AutoMacro {
namespace History {
void KeyboardHistoryAgentTest::TestKeyboardHistoryAgent() {
    Histories histories;
    Keyboard* keyboard = Factory::createMockKeyboard();
    keyboard = Factory::addHistoryAgent(keyboard, &histories);

    keyboard->pressKey(KeyCode::KEY_A);
    HistoryAssert::areEqual(histories.back(), "pressKey", KeyCode::KEY_A);

    keyboard->releaseKey(KeyCode::KEY_B);
    HistoryAssert::areEqual(histories.back(), "releaseKey", KeyCode::KEY_B);

    keyboard->releaseAllKeys();
    HistoryAssert::areEqual(histories.back(), "releaseAllKeys");
}
}  // namespace History
}  // namespace AutoMacro
