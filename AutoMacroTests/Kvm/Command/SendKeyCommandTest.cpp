#include "AutoMacro/Kvm/Kvm.h"
#include "AutoMacro/Util/Util.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(SendKeyCommandTest) {
public:
TEST_METHOD(TestSendKeyCommand){
    Histories histories;
    auto keyboard = Factory::createMockKeyboard();
    auto delay = Factory::createMockDelay();
    keyboard = Util::addHistoryAgent(keyboard, &histories);
    delay = Util::addHistoryAgent(delay, &histories);

    KeyCode key = KeyCode::KEY_A;
    int dBeforeCmd = 1;
    int dAfterCmd = 2;
    int dBetweenPKeyAndRKey = 3;
    int dBetweenRp = 4;
    int repeatTimes = 2;

    SendKeyCommandParameter p(keyboard, nullptr, nullptr, delay, key);
    p.delayBeforeCommand = dBeforeCmd;
    p.delayAfterCommand = dAfterCmd;
    p.delayBetweenPressKeyAndReleaseKey = dBetweenPKeyAndRKey;
    p.delayBetweenRepeatitions = dBetweenRp;
    p.repeatTimes = repeatTimes;

    auto cmd = Factory::createCommand(&p);

    histories.record("---");
    cmd->execute();
    histories.record("---");

    int idx = 0;
    Assert::IsTrue(histories[idx++].equals("---"));
    Assert::IsTrue(histories[idx++].equals("delay", dBeforeCmd));
    Assert::IsTrue(histories[idx++].equals("pressKey", key));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenPKeyAndRKey));
    Assert::IsTrue(histories[idx++].equals("releaseKey", key));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenRp));
    Assert::IsTrue(histories[idx++].equals("pressKey", key));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenPKeyAndRKey));
    Assert::IsTrue(histories[idx++].equals("releaseKey", key));
    Assert::IsTrue(histories[idx++].equals("delay", dAfterCmd));
    Assert::IsTrue(histories[idx++].equals("---"));
}
};
}  // namespace CommandTest
}  // namespace AutoMacro
