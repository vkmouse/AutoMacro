#include "AutoMacro/Kvm/Kvm.h"
#include "AutoMacro/Util/Util.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(DesktopSwitchCommandTest) {
public:
TEST_METHOD_INITIALIZE(methodInitialize) {
    Histories histories;
    auto keyboard = Factory::createMockKeyboard();
    auto delay = Factory::createMockDelay();
    keyboard = Util::addHistoryAgent(keyboard, &histories);
    delay = Util::addHistoryAgent(delay, &histories);

    int dBeforeCmd = 1;
    int dAfterCmd = 2;
    int dBetweenEachSwitch = 3;

    DesktopSwitchCommandParameter p(keyboard, nullptr, nullptr, delay, 3, 1);
    p.delayBeforeCommand = dBeforeCmd;
    p.delayAfterCommand = dAfterCmd;
    p.delayBetweemEachSwitch = dBetweenEachSwitch;

    auto cmd = Factory::createCommand(&p);

    histories.record("---");
    cmd->execute();
    histories.record("---");

    int dBeforeShortcut = 0;
    int dAfterShortcut = 0;
    int dBetweenEachPKey = 0;
    int dBetweenEachRKey = 0;
    int dBetweenPkeyAndRKey = 1;

    int idx = 0;
    Assert::IsTrue(histories[idx++].equals("---"));
    Assert::IsTrue(histories[idx++].equals("delay", dBeforeCmd));
    Assert::IsTrue(histories[idx++].equals("delay", dBeforeShortcut));
    Assert::IsTrue(histories[idx++].equals("pressKey", KeyCode::KEY_LCTRL));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenEachPKey));
    Assert::IsTrue(histories[idx++].equals("pressKey", KeyCode::KEY_LMETA));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenEachPKey));
    Assert::IsTrue(histories[idx++].equals("pressKey", KeyCode::KEY_LEFT));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenPkeyAndRKey));
    Assert::IsTrue(histories[idx++].equals("releaseKey", KeyCode::KEY_LEFT));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenEachRKey));
    Assert::IsTrue(histories[idx++].equals("releaseKey", KeyCode::KEY_LMETA));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenEachRKey));
    Assert::IsTrue(histories[idx++].equals("releaseKey", KeyCode::KEY_LCTRL));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenEachSwitch));
    Assert::IsTrue(histories[idx++].equals("pressKey", KeyCode::KEY_LCTRL));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenEachPKey));
    Assert::IsTrue(histories[idx++].equals("pressKey", KeyCode::KEY_LMETA));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenEachPKey));
    Assert::IsTrue(histories[idx++].equals("pressKey", KeyCode::KEY_LEFT));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenPkeyAndRKey));
    Assert::IsTrue(histories[idx++].equals("releaseKey", KeyCode::KEY_LEFT));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenEachRKey));
    Assert::IsTrue(histories[idx++].equals("releaseKey", KeyCode::KEY_LMETA));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenEachRKey));
    Assert::IsTrue(histories[idx++].equals("releaseKey", KeyCode::KEY_LCTRL));
    Assert::IsTrue(histories[idx++].equals("delay", dAfterShortcut));
    Assert::IsTrue(histories[idx++].equals("delay", dAfterCmd));
    Assert::IsTrue(histories[idx++].equals("---"));
}

TEST_METHOD_CLEANUP(methodCleanup) {
    Histories histories;
    auto keyboard = Factory::createMockKeyboard();
    auto delay = Factory::createMockDelay();
    keyboard = Util::addHistoryAgent(keyboard, &histories);
    delay = Util::addHistoryAgent(delay, &histories);

    int dBeforeCmd = 1;
    int dAfterCmd = 2;

    DesktopSwitchCommandParameter p(keyboard, nullptr, nullptr, delay, 1, 1);
    p.delayBeforeCommand = dBeforeCmd;
    p.delayAfterCommand = dAfterCmd;

    auto cmd = Factory::createCommand(&p);

    histories.record("---");
    cmd->execute();
    histories.record("---");

    int idx = 0;
    Assert::IsTrue(histories[idx++].equals("---"));
    Assert::IsTrue(histories[idx++].equals("delay", dBeforeCmd));
    Assert::IsTrue(histories[idx++].equals("delay", dAfterCmd));
    Assert::IsTrue(histories[idx++].equals("---"));
}

TEST_METHOD(TestDesktopSwitch) {
    Histories histories;
    auto keyboard = Factory::createMockKeyboard();
    auto delay = Factory::createMockDelay();
    keyboard = Util::addHistoryAgent(keyboard, &histories);
    delay = Util::addHistoryAgent(delay, &histories);

    int dBeforeCmd = 1;
    int dAfterCmd = 2;

    DesktopSwitchCommandParameter p1(keyboard, nullptr, nullptr, delay, 3, 1);
    p1.delayBeforeCommand = dBeforeCmd;
    p1.delayAfterCommand = dAfterCmd;
    DesktopSwitchCommandParameter p2(keyboard, nullptr, nullptr, delay, 3, 2);
    p2.delayBeforeCommand = dBeforeCmd;
    p2.delayAfterCommand = dAfterCmd;

    auto cmd1 = Factory::createCommand(&p1);
    auto cmd2 = Factory::createCommand(&p2);

    histories.record("---");
    cmd1->execute();
    histories.record("---");
    cmd2->execute();
    histories.record("---");

    int dBeforeShortcut = 0;
    int dAfterShortcut = 0;
    int dBetweenEachPKey = 0;
    int dBetweenEachRKey = 0;
    int dBetweenPkeyAndRKey = 1;

    int idx = 0;
    Assert::IsTrue(histories[idx++].equals("---"));
    Assert::IsTrue(histories[idx++].equals("delay", dBeforeCmd));
    Assert::IsTrue(histories[idx++].equals("delay", dAfterCmd));
    Assert::IsTrue(histories[idx++].equals("---"));
    Assert::IsTrue(histories[idx++].equals("delay", dBeforeCmd));
    Assert::IsTrue(histories[idx++].equals("delay", dBeforeShortcut));
    Assert::IsTrue(histories[idx++].equals("pressKey", KeyCode::KEY_LCTRL));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenEachPKey));
    Assert::IsTrue(histories[idx++].equals("pressKey", KeyCode::KEY_LMETA));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenEachPKey));
    Assert::IsTrue(histories[idx++].equals("pressKey", KeyCode::KEY_RIGHT));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenPkeyAndRKey));
    Assert::IsTrue(histories[idx++].equals("releaseKey", KeyCode::KEY_RIGHT));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenEachRKey));
    Assert::IsTrue(histories[idx++].equals("releaseKey", KeyCode::KEY_LMETA));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenEachRKey));
    Assert::IsTrue(histories[idx++].equals("releaseKey", KeyCode::KEY_LCTRL));
    Assert::IsTrue(histories[idx++].equals("delay", dAfterShortcut));
    Assert::IsTrue(histories[idx++].equals("delay", dAfterCmd));
    Assert::IsTrue(histories[idx++].equals("---"));
}
};
}  // namespace CommandTest
}  // namespace AutoMacro
