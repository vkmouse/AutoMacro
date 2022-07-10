#include "AutoMacro/Command/Command.h"
#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Util/Util.h"
#include "AutoMacroTests/Command/CommandTest.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(ShortcutCommandTest) {
std::vector<KeyCode> keys = { KeyCode::KEY_LALT, KeyCode::KEY_TAB };
int delayBeforeCommand = 1;
int delayAfterCommand = 2;
int dBetweenEachPKey = 3;
int dBetweenEachRKey = 4;
int delayBetweenPressKeyAndReleaseKey = 5;
int delayBetweenRepeatitions = 6;
int repeatTimes = 2;

public:
TEST_METHOD(TestShortcutCommand) {
    Histories h;
    ShortcutCommandParameter p(getKvm(&h), keys);
    p.delayBeforeCommand = delayBeforeCommand;
    p.delayAfterCommand = delayAfterCommand;
    p.delayBetweenEachPressKey = dBetweenEachPKey;
    p.delayBetweenEachReleaseKey = dBetweenEachRKey;
    p.delayBetweenPressKeyAndReleaseKey = delayBetweenPressKeyAndReleaseKey;
    p.delayBetweenRepeatitions = delayBetweenRepeatitions;
    p.repeatTimes = repeatTimes;

    execute(&h, p);

    int i = 0;
    Assert::IsTrue(h[i++].equals("---"));
    Assert::IsTrue(h[i++].equals("delay", delayBeforeCommand));
    Assert::IsTrue(h[i++].equals("pressKey", keys[0]));
    Assert::IsTrue(h[i++].equals("delay", dBetweenEachPKey));
    Assert::IsTrue(h[i++].equals("pressKey", keys[1]));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenPressKeyAndReleaseKey));
    Assert::IsTrue(h[i++].equals("releaseKey", keys[1]));
    Assert::IsTrue(h[i++].equals("delay", dBetweenEachRKey));
    Assert::IsTrue(h[i++].equals("releaseKey", keys[0]));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenRepeatitions));
    Assert::IsTrue(h[i++].equals("pressKey", keys[0]));
    Assert::IsTrue(h[i++].equals("delay", dBetweenEachPKey));
    Assert::IsTrue(h[i++].equals("pressKey", keys[1]));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenPressKeyAndReleaseKey));
    Assert::IsTrue(h[i++].equals("releaseKey", keys[1]));
    Assert::IsTrue(h[i++].equals("delay", dBetweenEachRKey));
    Assert::IsTrue(h[i++].equals("releaseKey", keys[0]));
    Assert::IsTrue(h[i++].equals("delay", delayAfterCommand));
    Assert::IsTrue(h[i++].equals("---"));
}
};
}  // namespace CommandTest
}  // namespace AutoMacro
