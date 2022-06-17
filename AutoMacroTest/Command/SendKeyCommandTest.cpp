#include "AutoMacroTest/Command/SendKeyCommandTest.h"

#include <AutoMacro/Command/SendKeyCommand.h>
#include <AutoMacro/History/History.h>
#include <AutoMacro/Keyboard/Keyboard.h>
#include "AutoMacroTest/History/HistoryAssert.h"

namespace AutoMacro {
namespace Command {
namespace {
using History::HistoryAssert;
}  // namespace

void SendKeyCommandTest::TestSendKeyCommand() {
    History::Histories histories;
    Keyboard* keyboard = Factory::createMockKeyboard();
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

    HistoryAssert::areEqual(histories[0], "---");
    HistoryAssert::areEqual(histories[1], "pressKey", KeyCode::KEY_A);
    HistoryAssert::areEqual(histories[2], "releaseKey", KeyCode::KEY_A);
    HistoryAssert::areEqual(histories[3], "pressKey", KeyCode::KEY_A);
    HistoryAssert::areEqual(histories[4], "releaseKey", KeyCode::KEY_A);
    HistoryAssert::areEqual(histories[5], "pressKey", KeyCode::KEY_A);
    HistoryAssert::areEqual(histories[6], "releaseKey", KeyCode::KEY_A);
    HistoryAssert::areEqual(histories[7], "---");

    HistoryAssert::AllDurationAreInRange(histories, {
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
