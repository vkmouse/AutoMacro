#include "AutoMacro/Kvm/Kvm.h"
#include "AutoMacro/Util/Util.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(MouseClickCommandTest) {
public:
TEST_METHOD(TestSingleClick) {
    Histories histories;
    auto mouse = Factory::createMockMouse();
    auto delay = Factory::createMockDelay();
    mouse = Util::addHistoryAgent(mouse, &histories);
    delay = Util::addHistoryAgent(delay, &histories);

    MouseButton button = MouseButton::BUTTON_LEFT;
    int dBeforeCmd = 1;
    int dAfterCmd = 2;
    int dBetweenPBtnAndRBtn = 3;

    MouseClickCommandParameter p(nullptr, mouse, nullptr, delay, button);
    p.delayBeforeCommand = dBeforeCmd;
    p.delayAfterCommand = dAfterCmd;
    p.delayBetweenMouseDownAndMouseUp = dBetweenPBtnAndRBtn;

    auto cmd = Factory::createCommand(&p);

    histories.record("---");
    cmd->execute();
    histories.record("---");

    int idx = 0;
    Assert::IsTrue(histories[idx++].equals("---"));
    Assert::IsTrue(histories[idx++].equals("delay", dBeforeCmd));
    Assert::IsTrue(histories[idx++].equals("mouseDown", button));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenPBtnAndRBtn));
    Assert::IsTrue(histories[idx++].equals("mouseUp", button));
    Assert::IsTrue(histories[idx++].equals("delay", dAfterCmd));
    Assert::IsTrue(histories[idx++].equals("---"));
}

TEST_METHOD(TestMultipleClick) {
    Histories histories;
    auto mouse = Factory::createMockMouse();
    auto delay = Factory::createMockDelay();
    mouse = Util::addHistoryAgent(mouse, &histories);
    delay = Util::addHistoryAgent(delay, &histories);

    MouseButton button = MouseButton::BUTTON_LEFT;
    int dBeforeCmd = 1;
    int dAfterCmd = 2;
    int dBetweenPBtnAndRBtn = 3;
    int dBetweenRp = 4;
    int repeatTimes = 2;

    MouseClickCommandParameter p(nullptr, mouse, nullptr, delay, button);
    p.delayBeforeCommand = dBeforeCmd;
    p.delayAfterCommand = dAfterCmd;
    p.delayBetweenMouseDownAndMouseUp = dBetweenPBtnAndRBtn;
    p.delayBetweenRepeatitions = dBetweenRp;
    p.repeatTimes = repeatTimes;

    auto cmd = Factory::createCommand(&p);

    histories.record("---");
    cmd->execute();
    histories.record("---");

    int idx = 0;
    Assert::IsTrue(histories[idx++].equals("---"));
    Assert::IsTrue(histories[idx++].equals("delay", dBeforeCmd));
    Assert::IsTrue(histories[idx++].equals("mouseDown", button));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenPBtnAndRBtn));
    Assert::IsTrue(histories[idx++].equals("mouseUp", button));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenRp));
    Assert::IsTrue(histories[idx++].equals("mouseDown", button));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenPBtnAndRBtn));
    Assert::IsTrue(histories[idx++].equals("mouseUp", button));
    Assert::IsTrue(histories[idx++].equals("delay", dAfterCmd));
    Assert::IsTrue(histories[idx++].equals("---"));
}

TEST_METHOD(TestMouseMoveAndClick) {
    Histories histories;
    auto mouse = Factory::createMockMouse();
    auto delay = Factory::createMockDelay();
    mouse = Util::addHistoryAgent(mouse, &histories);
    delay = Util::addHistoryAgent(delay, &histories);

    MouseButton button = MouseButton::BUTTON_LEFT;
    int dBeforeCmd = 1;
    int dAfterCmd = 2;
    int dBetweenPBtnAndRBtn = 3;
    int x = 321;
    int y = 123;
    int dBeforeMove = 4;
    int dAfterMove = 5;

    MouseClickCommandParameter p(nullptr, mouse, nullptr, delay, button, x, y);
    p.delayBeforeCommand = dBeforeCmd;
    p.delayAfterCommand = dAfterCmd;
    p.delayBetweenMouseDownAndMouseUp = dBetweenPBtnAndRBtn;
    p.delayBeforeMove = dBeforeMove;
    p.delayAfterMove = dAfterMove;

    auto cmd = Factory::createCommand(&p);

    histories.record("---");
    cmd->execute();
    histories.record("---");

    int idx = 0;
    Assert::IsTrue(histories[idx++].equals("---"));
    Assert::IsTrue(histories[idx++].equals("delay", dBeforeCmd));
    Assert::IsTrue(histories[idx++].equals("delay", dBeforeMove));
    Assert::IsTrue(histories[idx++].equals("mouseMove", x, y));
    Assert::IsTrue(histories[idx++].equals("delay", dAfterMove));
    Assert::IsTrue(histories[idx++].equals("mouseDown", button));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenPBtnAndRBtn));
    Assert::IsTrue(histories[idx++].equals("mouseUp", button));
    Assert::IsTrue(histories[idx++].equals("delay", dAfterCmd));
    Assert::IsTrue(histories[idx++].equals("---"));
}
};
}  // namespace CommandTest
}  // namespace AutoMacro
