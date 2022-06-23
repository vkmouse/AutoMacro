#include "AutoMacroTest/Command/DesktopSwitchCommandTest.h"

#include <AutoMacro/Command/Command.h>
#include <AutoMacro/History/History.h>
#include <AutoMacro/KbdMou/KbdMou.h>

namespace AutoMacro {
namespace Command {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

void DesktopSwitchCommandTest::methodInitialize() {
    History::Histories histories;
    auto keyboard = Factory::createMockKeyboard();
    keyboard = Factory::addHistoryAgent(keyboard, &histories);

    DesktopSwitchCommandParameter p(keyboard, 3, 1);
    auto cmd = Factory::createCommand(&p);

    histories.record("---");
    cmd->execute();
    histories.record("---");

    Assert::IsTrue(histories[0].equals("---"));
    Assert::IsTrue(histories[1].equals("pressKey", KeyCode::KEY_LCTRL));
    Assert::IsTrue(histories[2].equals("pressKey", KeyCode::KEY_LMETA));
    Assert::IsTrue(histories[3].equals("pressKey", KeyCode::KEY_LEFT));
    Assert::IsTrue(histories[4].equals("releaseKey", KeyCode::KEY_LEFT));
    Assert::IsTrue(histories[5].equals("releaseKey", KeyCode::KEY_LMETA));
    Assert::IsTrue(histories[6].equals("releaseKey", KeyCode::KEY_LCTRL));
    Assert::IsTrue(histories[7].equals("pressKey", KeyCode::KEY_LCTRL));
    Assert::IsTrue(histories[8].equals("pressKey", KeyCode::KEY_LMETA));
    Assert::IsTrue(histories[9].equals("pressKey", KeyCode::KEY_LEFT));
    Assert::IsTrue(histories[10].equals("releaseKey", KeyCode::KEY_LEFT));
    Assert::IsTrue(histories[11].equals("releaseKey", KeyCode::KEY_LMETA));
    Assert::IsTrue(histories[12].equals("releaseKey", KeyCode::KEY_LCTRL));
    Assert::IsTrue(histories[13].equals("---"));
}

void DesktopSwitchCommandTest::methodCleanup() {
    History::Histories histories;
    auto keyboard = Factory::createMockKeyboard();
    keyboard = Factory::addHistoryAgent(keyboard, &histories);

    DesktopSwitchCommandParameter p(keyboard, 1, 1);
    auto cmd = Factory::createCommand(&p);

    histories.record("---");
    cmd->execute();
    histories.record("---");

    Assert::IsTrue(histories[0].equals("---"));
    Assert::IsTrue(histories[1].equals("---"));
}

void DesktopSwitchCommandTest::TestDesktopSwitch() {
    History::Histories histories;
    auto keyboard = Factory::createMockKeyboard();
    keyboard = Factory::addHistoryAgent(keyboard, &histories);

    DesktopSwitchCommandParameter p1(keyboard, 3, 1);
    DesktopSwitchCommandParameter p2(keyboard, 3, 2);
    auto cmd1 = Factory::createCommand(&p1);
    auto cmd2 = Factory::createCommand(&p2);

    histories.record("---");
    cmd1->execute();
    histories.record("---");
    cmd2->execute();
    histories.record("---");

    Assert::IsTrue(histories[0].equals("---"));
    Assert::IsTrue(histories[1].equals("---"));
    Assert::IsTrue(histories[2].equals("pressKey", KeyCode::KEY_LCTRL));
    Assert::IsTrue(histories[3].equals("pressKey", KeyCode::KEY_LMETA));
    Assert::IsTrue(histories[4].equals("pressKey", KeyCode::KEY_RIGHT));
    Assert::IsTrue(histories[5].equals("releaseKey", KeyCode::KEY_RIGHT));
    Assert::IsTrue(histories[6].equals("releaseKey", KeyCode::KEY_LMETA));
    Assert::IsTrue(histories[7].equals("releaseKey", KeyCode::KEY_LCTRL));
    Assert::IsTrue(histories[8].equals("---"));
}

void DesktopSwitchCommandTest::TestDelayBetweenEachSwitch() {
    History::Histories histories;
    auto keyboard = Factory::createMockKeyboard();
    keyboard = Factory::addHistoryAgent(keyboard, &histories);

    DesktopSwitchCommandParameter p(keyboard, 3, 3);
    p.delayBetweemEachSwitch = 100;
    auto cmd = Factory::createCommand(&p);

    histories.record("---");
    cmd->execute();
    histories.record("---");

    int idx = 0;
    Assert::IsTrue(histories[idx++].equals("---"));
    Assert::IsTrue(histories[idx++].equals("pressKey", KeyCode::KEY_LCTRL));
    Assert::IsTrue(histories[idx++].equals("pressKey", KeyCode::KEY_LMETA));
    Assert::IsTrue(histories[idx++].equals("pressKey", KeyCode::KEY_RIGHT));
    Assert::IsTrue(histories[idx++].equals("releaseKey", KeyCode::KEY_RIGHT));
    Assert::IsTrue(histories[idx++].equals("releaseKey", KeyCode::KEY_LMETA));
    Assert::IsTrue(histories[idx++].equals("releaseKey", KeyCode::KEY_LCTRL));
    Assert::IsTrue(histories[idx++].equals("pressKey", KeyCode::KEY_LCTRL));
    Assert::IsTrue(histories[idx++].equals("pressKey", KeyCode::KEY_LMETA));
    Assert::IsTrue(histories[idx++].equals("pressKey", KeyCode::KEY_RIGHT));
    Assert::IsTrue(histories[idx++].equals("releaseKey", KeyCode::KEY_RIGHT));
    Assert::IsTrue(histories[idx++].equals("releaseKey", KeyCode::KEY_LMETA));
    Assert::IsTrue(histories[idx++].equals("releaseKey", KeyCode::KEY_LCTRL));
    Assert::IsTrue(histories[idx++].equals("---"));

    bool allDurationsAreInRange = History::History::durationIsInRange(histories[6], histories[7],
        p.delayBetweemEachSwitch,
        p.delayBetweemEachSwitch + 40);
    Assert::IsTrue(allDurationsAreInRange);
}
}  // namespace Command
}  // namespace AutoMacro
