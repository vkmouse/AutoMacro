#include "AutoMacro/Kvm/Kvm.h"
#include "AutoMacro/Util/Util.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(ShortcutCommandTest) {
public:
TEST_METHOD(TestShortcutCommand) {
    Histories histories;
    auto keyboard = Factory::createMockKeyboard();
    auto delay = Factory::createMockDelay();
    keyboard = Util::addHistoryAgent(keyboard, &histories);
    delay = Util::addHistoryAgent(delay, &histories);

    std::vector<KeyCode> keys = { KeyCode::KEY_LALT, KeyCode::KEY_TAB };
    int dBeforeCmd = 1;
    int dAfterCmd = 2;
    int dBetweenEachPKey = 3;
    int dBetweenEachRKey = 4;
    int dBetweenPkeyAndRKey = 5;
    int dBetweenRp = 6;
    int repeatTimes = 2;

    ShortcutCommandParameter p(keyboard, nullptr, nullptr, delay, keys);
    p.delayBeforeCommand = dBeforeCmd;
    p.delayAfterCommand = dAfterCmd;
    p.delayBetweenEachPressKey = dBetweenEachPKey;
    p.delayBetweenEachReleaseKey = dBetweenEachRKey;
    p.delayBetweenPressKeyAndReleaseKey = dBetweenPkeyAndRKey;
    p.delayBetweenRepeatitions = dBetweenRp;
    p.repeatTimes = repeatTimes;

    auto cmd = Factory::createCommand(&p);

    histories.record("---");
    cmd->execute();
    histories.record("---");

    int idx = 0;
    Assert::IsTrue(histories[idx++].equals("---"));
    Assert::IsTrue(histories[idx++].equals("delay", dBeforeCmd));
    Assert::IsTrue(histories[idx++].equals("pressKey", keys[0]));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenEachPKey));
    Assert::IsTrue(histories[idx++].equals("pressKey", keys[1]));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenPkeyAndRKey));
    Assert::IsTrue(histories[idx++].equals("releaseKey", keys[1]));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenEachRKey));
    Assert::IsTrue(histories[idx++].equals("releaseKey", keys[0]));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenRp));
    Assert::IsTrue(histories[idx++].equals("pressKey", keys[0]));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenEachPKey));
    Assert::IsTrue(histories[idx++].equals("pressKey", keys[1]));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenPkeyAndRKey));
    Assert::IsTrue(histories[idx++].equals("releaseKey", keys[1]));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenEachRKey));
    Assert::IsTrue(histories[idx++].equals("releaseKey", keys[0]));
    Assert::IsTrue(histories[idx++].equals("delay", dAfterCmd));
    Assert::IsTrue(histories[idx++].equals("---"));
}
};
}  // namespace CommandTest
}  // namespace AutoMacro
