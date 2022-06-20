#include "AutoMacroTest/Command/SendKeyCommandTest.h"

#include <AutoMacro/Command/SendKeyCommand.h>
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

    SendKeyCommand cmd(keyboard, KeyCode::KEY_A);
    cmd.delayBeforeCommand = 50;
    cmd.delayAfterCommand = 50;
    cmd.delayBetweenCommands = 50;
    cmd.delayBetweenRepeatitions = 50;
    cmd.repeatTimes = 3;
    int tolerence = 40;

    histories.record("---");
    cmd.execute();
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
        cmd.delayBeforeCommand,
        cmd.delayBetweenCommands,
        cmd.delayBetweenRepeatitions,
        cmd.delayBetweenCommands,
        cmd.delayBetweenRepeatitions,
        cmd.delayBetweenCommands,
        cmd.delayAfterCommand
        }, tolerence);
}
}  // namespace Command
}  // namespace AutoMacro
