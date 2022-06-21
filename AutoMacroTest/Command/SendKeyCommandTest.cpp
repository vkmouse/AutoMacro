#include "AutoMacroTest/Command/SendKeyCommandTest.h"

#include <AutoMacro/Command/Command.h>
#include <AutoMacro/History/History.h>
#include <AutoMacro/Keyboard/Keyboard.h>

namespace AutoMacro {
namespace Command {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

void SendKeyCommandTest::TestSendKeyCommand() {
    History::Histories histories;
    auto keyboard = Factory::createMockKeyboard();
    keyboard = Factory::addHistoryAgent(keyboard, &histories);

    SendKeyCommandParameter p(keyboard, KeyCode::KEY_A);
    p.delayBeforeCommand = 50;
    p.delayAfterCommand = 50;
    p.delayBetweenPressKeyAndReleaseKey = 50;
    p.delayBetweenRepeatitions = 50;
    p.repeatTimes = 3;

    auto cmd = Factory::createCommand(&p);

    histories.record("---");
    cmd->execute();
    histories.record("---");

    Assert::IsTrue(histories[0].equals("---"));
    Assert::IsTrue(histories[1].equals("pressKey", KeyCode::KEY_A));
    Assert::IsTrue(histories[2].equals("releaseKey", KeyCode::KEY_A));
    Assert::IsTrue(histories[3].equals("pressKey", KeyCode::KEY_A));
    Assert::IsTrue(histories[4].equals("releaseKey", KeyCode::KEY_A));
    Assert::IsTrue(histories[5].equals("pressKey", KeyCode::KEY_A));
    Assert::IsTrue(histories[6].equals("releaseKey", KeyCode::KEY_A));
    Assert::IsTrue(histories[7].equals("---"));

    histories.allDurationsAreInRange({
        p.delayBeforeCommand,
        p.delayBetweenPressKeyAndReleaseKey,
        p.delayBetweenRepeatitions,
        p.delayBetweenPressKeyAndReleaseKey,
        p.delayBetweenRepeatitions,
        p.delayBetweenPressKeyAndReleaseKey,
        p.delayAfterCommand
        }, 40);
}
}  // namespace Command
}  // namespace AutoMacro
