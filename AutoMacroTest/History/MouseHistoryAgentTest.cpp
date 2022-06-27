#include "AutoMacroTest/History/MouseHistoryAgentTest.h"

#include "AutoMacro/History/History.h"
#include "AutoMacro/KbdMou/KbdMou.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace History {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

void MouseHistoryAgentTest::TestMouseHistoryAgent() {
    Histories histories;
    auto mouse = Factory::createMockMouse();
    mouse = Factory::addHistoryAgent(mouse, &histories);

    mouse->mouseDown(MouseButton::BUTTON_LEFT);
    Assert::IsTrue(
        histories.back().equals("mouseDown", MouseButton::BUTTON_LEFT));

    mouse->mouseUp(MouseButton::BUTTON_LEFT);
    Assert::IsTrue(
        histories.back().equals("mouseUp", MouseButton::BUTTON_LEFT));

    mouse->releaseAllButtons();
    Assert::IsTrue(histories.back().equals("releaseAllButtons"));

    mouse->mouseMove(321, 123);
    Assert::IsTrue(histories.back().equals("mouseMove", 321, 123));
}
}  // namespace History
}  // namespace AutoMacro
