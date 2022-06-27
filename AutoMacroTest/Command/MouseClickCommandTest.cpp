#include "AutoMacroTest/Command/MouseClickCommandTest.h"

#include <vector>

#include "AutoMacro/Command/Command.h"
#include "AutoMacro/History/History.h"
#include "AutoMacro/KbdMou/KbdMou.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace Command {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

void MouseClickCommandTest::TestSingleClick() {
    History::Histories histories;
    auto mouse = Factory::createMockMouse();
    mouse = Factory::addHistoryAgent(mouse, &histories);

    MouseClickCommandParameter p(mouse, MouseButton::BUTTON_LEFT);
    p.delayBeforeCommand = 50;
    p.delayAfterCommand = 50;
    p.delayBetweenMouseDownAndMouseUp = 50;

    auto cmd = Factory::createCommand(&p);

    histories.record("---");
    cmd->execute();
    histories.record("---");

    int idx = 0;
    std::vector<bool> allAreEqual = {
        histories[idx++].equals("---"),
        histories[idx++].equals("mouseDown", MouseButton::BUTTON_LEFT),
        histories[idx++].equals("mouseUp", MouseButton::BUTTON_LEFT),
        histories[idx++].equals("---"),
    };
    for (auto isEqual : allAreEqual) {
        Assert::IsTrue(isEqual);
    }

    bool allDurationsAreInRange = histories.allDurationsAreInRange({
        p.delayBeforeCommand,
        p.delayBetweenMouseDownAndMouseUp,
        p.delayAfterCommand
        }, 40);
    Assert::IsTrue(allDurationsAreInRange);
}

void MouseClickCommandTest::TestMultipleClick() {
    History::Histories histories;
    auto mouse = Factory::createMockMouse();
    mouse = Factory::addHistoryAgent(mouse, &histories);

    MouseClickCommandParameter p(mouse, MouseButton::BUTTON_LEFT);
    p.delayBeforeCommand = 50;
    p.delayAfterCommand = 50;
    p.delayBetweenMouseDownAndMouseUp = 50;
    p.delayBetweenRepeatitions = 50;
    p.repeatTimes = 3;

    auto cmd = Factory::createCommand(&p);

    histories.record("---");
    cmd->execute();
    histories.record("---");

    int idx = 0;
    std::vector<bool> allAreEqual = {
        histories[idx++].equals("---"),
        histories[idx++].equals("mouseDown", MouseButton::BUTTON_LEFT),
        histories[idx++].equals("mouseUp", MouseButton::BUTTON_LEFT),
        histories[idx++].equals("mouseDown", MouseButton::BUTTON_LEFT),
        histories[idx++].equals("mouseUp", MouseButton::BUTTON_LEFT),
        histories[idx++].equals("mouseDown", MouseButton::BUTTON_LEFT),
        histories[idx++].equals("mouseUp", MouseButton::BUTTON_LEFT),
        histories[idx++].equals("---"),
    };
    for (auto isEqual : allAreEqual) {
        Assert::IsTrue(isEqual);
    }

    bool allDurationsAreInRange = histories.allDurationsAreInRange({
        p.delayBeforeCommand,
        p.delayBetweenMouseDownAndMouseUp,
        p.delayBetweenRepeatitions,
        p.delayBetweenMouseDownAndMouseUp,
        p.delayBetweenRepeatitions,
        p.delayBetweenMouseDownAndMouseUp,
        p.delayAfterCommand
        }, 40);
    Assert::IsTrue(allDurationsAreInRange);
}

void MouseClickCommandTest::TestMouseMoveAndClick() {
    History::Histories histories;
    auto mouse = Factory::createMockMouse();
    mouse = Factory::addHistoryAgent(mouse, &histories);

    MouseClickCommandParameter p(mouse, MouseButton::BUTTON_LEFT);
    p.delayBeforeCommand = 50;
    p.delayAfterCommand = 50;
    p.delayBetweenMouseDownAndMouseUp = 50;
    p.delayBetweenRepeatitions = 50;
    p.repeatTimes = 2;

    MouseMoveCommandParameter moveParam(mouse, 456, 654);
    moveParam.delayBeforeCommand = 50;
    moveParam.delayAfterCommand = 50;

    p.enableMouseMove = true;
    p.mouseMoveCommandParameter = moveParam;

    auto cmd = Factory::createCommand(&p);

    histories.record("---");
    cmd->execute();
    histories.record("---");

    int idx = 0;
    std::vector<bool> allAreEqual = {
        histories[idx++].equals("---"),
        histories[idx++].equals("mouseMove", 456, 654),
        histories[idx++].equals("mouseDown", MouseButton::BUTTON_LEFT),
        histories[idx++].equals("mouseUp", MouseButton::BUTTON_LEFT),
        histories[idx++].equals("mouseDown", MouseButton::BUTTON_LEFT),
        histories[idx++].equals("mouseUp", MouseButton::BUTTON_LEFT),
        histories[idx++].equals("---"),
    };
    for (auto isEqual : allAreEqual) {
        Assert::IsTrue(isEqual);
    }

    bool allDurationsAreInRange = histories.allDurationsAreInRange({
        p.delayBeforeCommand + moveParam.delayBeforeCommand,
        moveParam.delayAfterCommand,
        p.delayBetweenMouseDownAndMouseUp,
        p.delayBetweenRepeatitions,
        p.delayBetweenMouseDownAndMouseUp,
        p.delayAfterCommand
        }, 40);
    Assert::IsTrue(allDurationsAreInRange);
}
}  // namespace Command
}  // namespace AutoMacro
