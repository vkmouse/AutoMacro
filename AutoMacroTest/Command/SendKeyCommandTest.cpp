#include "AutoMacroTest/Command/SendKeyCommandTest.h"

#include <AutoMacro/Command/SendKeyCommand.h>
#include <AutoMacro/History/History.h>
#include <AutoMacro/History/HistoryAgent.h>
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
    keyboard = Factory::addKeyboardHistoryAgent(keyboard, &histories);

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

    HistoryAssert::durationIsInRange(histories[1], histories[2],
        cmd.delayBetweenCommands, cmd.delayBetweenCommands + tolerence);
    HistoryAssert::durationIsInRange(histories[3], histories[4],
        cmd.delayBetweenCommands, cmd.delayBetweenCommands + tolerence);
    HistoryAssert::durationIsInRange(histories[5], histories[6],
        cmd.delayBetweenCommands, cmd.delayBetweenCommands + tolerence);

    HistoryAssert::durationIsInRange(histories[2], histories[3],
        cmd.delayBetweenRepeatitions, cmd.delayBetweenRepeatitions + tolerence);
    HistoryAssert::durationIsInRange(histories[4], histories[5],
        cmd.delayBetweenRepeatitions, cmd.delayBetweenRepeatitions + tolerence);

    HistoryAssert::durationIsInRange(histories[0], histories[1],
        cmd.delayBeforeCommand, cmd.delayBeforeCommand + tolerence);
    HistoryAssert::durationIsInRange(histories[6], histories[7],
        cmd.delayAfterCommand, cmd.delayAfterCommand + tolerence);
}
}  // namespace Command
}  // namespace AutoMacro
