#include "AutoMacroTest/Command/MouseMoveCommandTest.h"

#include "AutoMacro/Command/Command.h"
#include "AutoMacro/History/History.h"
#include "AutoMacro/KbdMou/KbdMou.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace Command {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

void MouseMoveCommandTest::TestMouseMoveCommand() {
    History::Histories histories;
    auto mouse = Factory::createMockMouse();
    mouse = Factory::addHistoryAgent(mouse, &histories);

    MouseMoveCommandParameter p(mouse, 321, 123);
    p.delayBeforeCommand = 50;
    p.delayAfterCommand = 50;

    auto cmd = Factory::createCommand(&p);

    histories.record("---");
    cmd->execute();
    histories.record("---");

    int idx = 0;
    Assert::IsTrue(histories[idx++].equals("---"));
    Assert::IsTrue(histories[idx++].equals("mouseMove", 321, 123));
    Assert::IsTrue(histories[idx++].equals("---"));

    bool allDurationsAreInRange = histories.allDurationsAreInRange({
        p.delayBeforeCommand,
        p.delayAfterCommand
        }, 40);
    Assert::IsTrue(allDurationsAreInRange);
}
}  // namespace Command
}  // namespace AutoMacro
