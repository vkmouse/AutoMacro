#include "AutoMacro/Kvm/Kvm.h"
#include "AutoMacro/Util/Util.h"
#include "AutoMacroTests/Kvm/Command/CommandTest.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
TEST_CLASS(MouseClickCommandTest) {
int delayBeforeCommand = 1;
int delayAfterCommand = 2;
int delayBetweenMouseDownAndMouseUp = 3;
int delayBetweenRepeatitions = 4;
int delayBeforeMove = 5;
int delayAfterMove = 6;
int x = 7;
int y = 8;
int repeatTimes = 2;

public:
TEST_METHOD(TestSingleClick) {
    Histories h;
    MouseClickCommandParameter p(getKvm(&h), MouseButton::BUTTON_LEFT);
    p.delayBeforeCommand = delayBeforeCommand;
    p.delayAfterCommand = delayAfterCommand;
    p.delayBetweenMouseDownAndMouseUp = delayBetweenMouseDownAndMouseUp;

    execute(&h, p);

    int i = 0;
    Assert::IsTrue(h[i++].equals("---"));
    Assert::IsTrue(h[i++].equals("delay", delayBeforeCommand));
    Assert::IsTrue(h[i++].equals("mouseDown", MouseButton::BUTTON_LEFT));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenMouseDownAndMouseUp));
    Assert::IsTrue(h[i++].equals("mouseUp", MouseButton::BUTTON_LEFT));
    Assert::IsTrue(h[i++].equals("delay", delayAfterCommand));
    Assert::IsTrue(h[i++].equals("---"));
}

TEST_METHOD(TestMultipleClick) {
    Histories h;
    MouseClickCommandParameter p(getKvm(&h), MouseButton::BUTTON_LEFT);
    p.delayBeforeCommand = delayBeforeCommand;
    p.delayAfterCommand = delayAfterCommand;
    p.delayBetweenMouseDownAndMouseUp = delayBetweenMouseDownAndMouseUp;
    p.delayBetweenRepeatitions = delayBetweenRepeatitions;
    p.repeatTimes = repeatTimes;

    execute(&h, p);

    int i = 0;
    Assert::IsTrue(h[i++].equals("---"));
    Assert::IsTrue(h[i++].equals("delay", delayBeforeCommand));
    Assert::IsTrue(h[i++].equals("mouseDown", MouseButton::BUTTON_LEFT));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenMouseDownAndMouseUp));
    Assert::IsTrue(h[i++].equals("mouseUp", MouseButton::BUTTON_LEFT));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenRepeatitions));
    Assert::IsTrue(h[i++].equals("mouseDown", MouseButton::BUTTON_LEFT));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenMouseDownAndMouseUp));
    Assert::IsTrue(h[i++].equals("mouseUp", MouseButton::BUTTON_LEFT));
    Assert::IsTrue(h[i++].equals("delay", delayAfterCommand));
    Assert::IsTrue(h[i++].equals("---"));
}

TEST_METHOD(TestMouseMoveAndClick) {
    Histories h;
    MouseClickCommandParameter p(getKvm(&h), MouseButton::BUTTON_LEFT, x, y);
    p.delayBeforeCommand = delayBeforeCommand;
    p.delayAfterCommand = delayAfterCommand;
    p.delayBetweenMouseDownAndMouseUp = delayBetweenMouseDownAndMouseUp;
    p.delayBeforeMove = delayBeforeMove;
    p.delayAfterMove = delayAfterMove;

    execute(&h, p);

    int i = 0;
    Assert::IsTrue(h[i++].equals("---"));
    Assert::IsTrue(h[i++].equals("delay", delayBeforeCommand));
    Assert::IsTrue(h[i++].equals("delay", delayBeforeMove));
    Assert::IsTrue(h[i++].equals("mouseMove", x, y));
    Assert::IsTrue(h[i++].equals("delay", delayAfterMove));
    Assert::IsTrue(h[i++].equals("mouseDown", MouseButton::BUTTON_LEFT));
    Assert::IsTrue(h[i++].equals("delay", p.delayBetweenMouseDownAndMouseUp));
    Assert::IsTrue(h[i++].equals("mouseUp", MouseButton::BUTTON_LEFT));
    Assert::IsTrue(h[i++].equals("delay", delayAfterCommand));
    Assert::IsTrue(h[i++].equals("---"));
}
};
}  // namespace CommandTest
}  // namespace AutoMacro
