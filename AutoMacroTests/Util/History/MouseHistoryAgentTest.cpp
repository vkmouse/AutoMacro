#include "AutoMacro/Util/Util.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace HistoryTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(MouseHistoryAgentTest) {
public:
TEST_METHOD(TestMouseHistoryAgent) {
    Histories histories;
    auto mouse = Factory::createMockMouse();
    mouse = Util::addHistoryAgent(mouse, &histories);

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
};
}  // namespace HistoryTest
}  // namespace AutoMacro
