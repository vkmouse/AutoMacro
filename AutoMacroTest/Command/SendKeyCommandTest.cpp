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

    SendKeyCommandParameter p(KeyCode::KEY_A);
    p.delayBeforeCommand = 50;
    p.delayAfterCommand = 50;
    p.delayBetweenCommands = 50;
    p.delayBetweenRepeatitions = 50;
    p.repeatTimes = 3;
    int tolerence = 40;

    Command* command = new SendKeyCommand(keyboard, p);

    histories.record("---");
    command->execute();
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
        p.delayBetweenCommands, p.delayBetweenCommands + tolerence);
    HistoryAssert::durationIsInRange(histories[3], histories[4],
        p.delayBetweenCommands, p.delayBetweenCommands + tolerence);
    HistoryAssert::durationIsInRange(histories[5], histories[6],
        p.delayBetweenCommands, p.delayBetweenCommands + tolerence);

    HistoryAssert::durationIsInRange(histories[2], histories[3],
        p.delayBetweenRepeatitions, p.delayBetweenRepeatitions + tolerence);
    HistoryAssert::durationIsInRange(histories[4], histories[5],
        p.delayBetweenRepeatitions, p.delayBetweenRepeatitions + tolerence);

    HistoryAssert::durationIsInRange(histories[0], histories[1],
        p.delayBeforeCommand, p.delayBeforeCommand + tolerence);
    HistoryAssert::durationIsInRange(histories[6], histories[7],
        p.delayAfterCommand, p.delayAfterCommand + tolerence);
    delete(command);
}
}  // namespace Command
}  // namespace AutoMacro
