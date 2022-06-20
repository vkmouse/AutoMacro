#include "AutoMacroTest/Command/WaitForItemCommandTest.h"

#include <memory>

#include <AutoMacro/Command/Command.h>
#include <AutoMacro/Detection/Detection.h>
#include <AutoMacro/History/History.h>
#include <AutoMacro/VideoCapture/VideoCapture.h>

namespace AutoMacro {
namespace Command {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

void WaitForItemCommandTest::TestWaitForItemExist() {
    auto videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\ItemNotExists_10x10_24bits.png",
        "images\\AutoMacroTest\\ItemNotExists_10x10_24bits.png",
        "images\\AutoMacroTest\\ItemExists_10x10_24bits.png" });

    History::Histories histories;
    videoCapture = Factory::addHistoryAgent(
        videoCapture, &histories);

    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\Template_5x5_24bits.png" });

    WaitForItemCommandParameter p(videoCapture, detector, 0, 0.98f);
    p.delayBeforeCommand = 50;
    p.delayAfterCommand = 50;
    p.delayBetweenRepeatitions = 100;
    p.waitForExists = true;

    auto cmd = Factory::createCommand(&p);

    histories.record("---");
    cmd->execute();
    histories.record("---");

    Assert::IsTrue(histories[0].equals("---"));
    Assert::IsTrue(histories[1].equals("takeSnapshot"));
    Assert::IsTrue(histories[2].equals("takeSnapshot"));
    Assert::IsTrue(histories[3].equals("takeSnapshot"));
    Assert::IsTrue(histories[4].equals("---"));

    histories.allDurationsAreInRange({
        p.delayBeforeCommand,
        p.delayBetweenRepeatitions,
        p.delayBetweenRepeatitions,
        p.delayAfterCommand
        }, 40);
}

void WaitForItemCommandTest::TestWaitForItemNotExist() {
    auto videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\ItemExists_10x10_24bits.png",
        "images\\AutoMacroTest\\ItemExists_10x10_24bits.png",
        "images\\AutoMacroTest\\ItemNotExists_10x10_24bits.png" });

    History::Histories histories;
    videoCapture = Factory::addHistoryAgent(
        videoCapture, &histories);

    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\Template_5x5_24bits.png" });

    WaitForItemCommandParameter p(videoCapture, detector, 0, 0.98f);
    p.delayBeforeCommand = 50;
    p.delayAfterCommand = 50;
    p.delayBetweenRepeatitions = 100;
    p.waitForExists = false;

    auto cmd = Factory::createCommand(&p);

    histories.record("---");
    cmd->execute();
    histories.record("---");

    Assert::IsTrue(histories[0].equals("---"));
    Assert::IsTrue(histories[1].equals("takeSnapshot"));
    Assert::IsTrue(histories[2].equals("takeSnapshot"));
    Assert::IsTrue(histories[3].equals("takeSnapshot"));
    Assert::IsTrue(histories[4].equals("---"));

    histories.allDurationsAreInRange({
        p.delayBeforeCommand,
        p.delayBetweenRepeatitions,
        p.delayBetweenRepeatitions,
        p.delayAfterCommand
        }, 40);
}
}  // namespace Command
}  // namespace AutoMacro
