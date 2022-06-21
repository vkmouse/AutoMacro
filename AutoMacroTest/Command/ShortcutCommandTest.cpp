#include "AutoMacroTest/Command/ShortcutCommandTest.h"

#include <AutoMacro/Command/Command.h>
#include <AutoMacro/History/History.h>
#include <AutoMacro/Keyboard/Keyboard.h>

namespace AutoMacro {
namespace Command {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

void ShortcutCommandTest::TestShortcutCommand() {
    History::Histories histories;
    auto keyboard = Factory::createMockKeyboard();
    keyboard = Factory::addHistoryAgent(keyboard, &histories);

    ShortcutCommandParameter p(keyboard,
        { KeyCode::KEY_LEFTALT, KeyCode::KEY_TAB });
    p.delayBeforeCommand = 50;
    p.delayAfterCommand = 50;
    p.delayBetweenEachPressKey = 50;
    p.delayBetweenEachReleaseKey = 50;
    p.delayBetweenPressKeyAndReleaseKey = 50;
    p.delayBetweenRepeatitions = 50;
    p.repeatTimes = 2;

    auto cmd = Factory::createCommand(&p);

    histories.record("---");
    cmd->execute();
    histories.record("---");

    Assert::IsTrue(histories[0].equals("---"));
    Assert::IsTrue(histories[1].equals("pressKey", KeyCode::KEY_LEFTALT));
    Assert::IsTrue(histories[2].equals("pressKey", KeyCode::KEY_TAB));
    Assert::IsTrue(histories[3].equals("releaseKey", KeyCode::KEY_TAB));
    Assert::IsTrue(histories[4].equals("releaseKey", KeyCode::KEY_LEFTALT));
    Assert::IsTrue(histories[5].equals("pressKey", KeyCode::KEY_LEFTALT));
    Assert::IsTrue(histories[6].equals("pressKey", KeyCode::KEY_TAB));
    Assert::IsTrue(histories[7].equals("releaseKey", KeyCode::KEY_TAB));
    Assert::IsTrue(histories[8].equals("releaseKey", KeyCode::KEY_LEFTALT));
    Assert::IsTrue(histories[9].equals("---"));

    histories.allDurationsAreInRange({
        p.delayBeforeCommand,
        p.delayBetweenEachPressKey,
        p.delayBetweenPressKeyAndReleaseKey,
        p.delayBetweenEachReleaseKey,
        p.delayBetweenRepeatitions,
        p.delayBetweenEachPressKey,
        p.delayBetweenPressKeyAndReleaseKey,
        p.delayBetweenEachReleaseKey,
        p.delayAfterCommand
        }, 40);
}
}  // namespace Command
}  // namespace AutoMacro
