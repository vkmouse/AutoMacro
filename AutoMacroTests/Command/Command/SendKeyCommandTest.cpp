#include "AutoMacro/Command/Command.h"
#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Util/Util.h"
#include "AutoMacroTests/Command/CommandTest.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(SendKeyCommandTest) {
int delayBeforeCommand = 1;
int delayAfterCommand = 2;
int delayBetweenPressKeyAndReleaseKey = 3;
int delayBetweenRepeatitions = 4;
int repeatTimes = 2;

public:
TEST_METHOD(TestSendKeyCommand){
    Histories h;
    SendKeyCommandParameter p(getKvm(&h), KeyCode::KEY_A);
    p.delayBeforeCommand = delayBeforeCommand;
    p.delayAfterCommand = delayAfterCommand;
    p.delayBetweenPressKeyAndReleaseKey = delayBetweenPressKeyAndReleaseKey;
    p.delayBetweenRepeatitions = delayBetweenRepeatitions;
    p.repeatTimes = repeatTimes;

    execute(&h, p);

    int i = 0;
    Assert::IsTrue(h[i++].equals("---"));
    Assert::IsTrue(h[i++].equals("delay", delayBeforeCommand));
    Assert::IsTrue(h[i++].equals("pressKey", KeyCode::KEY_A));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenPressKeyAndReleaseKey));
    Assert::IsTrue(h[i++].equals("releaseKey", KeyCode::KEY_A));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenRepeatitions));
    Assert::IsTrue(h[i++].equals("pressKey", KeyCode::KEY_A));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenPressKeyAndReleaseKey));
    Assert::IsTrue(h[i++].equals("releaseKey", KeyCode::KEY_A));
    Assert::IsTrue(h[i++].equals("delay", delayAfterCommand));
    Assert::IsTrue(h[i++].equals("---"));
}
};
}  // namespace CommandTest
}  // namespace AutoMacro
