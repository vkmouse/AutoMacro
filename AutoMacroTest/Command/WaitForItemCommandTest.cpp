#include "AutoMacroTest/Command/WaitForItemCommandTest.h"

#include <memory>

#include <AutoMacro/Command/WaitForItemCommand.h>
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

    WaitForItemCommand cmd(videoCapture, detector, 0, 0.98f);
    cmd.delayBeforeCommand = 50;
    cmd.delayAfterCommand = 50;
    cmd.delayBetweenRepeatitions = 100;
    cmd.waitForExists = true;

    histories.record("---");
    cmd.execute();
    histories.record("---");

    Assert::IsTrue(histories[0].equals("---"));
    Assert::IsTrue(histories[1].equals("takeSnapshot"));
    Assert::IsTrue(histories[2].equals("takeSnapshot"));
    Assert::IsTrue(histories[3].equals("takeSnapshot"));
    Assert::IsTrue(histories[4].equals("---"));

    histories.allDurationsAreInRange({
        cmd.delayBeforeCommand,
        cmd.delayBetweenRepeatitions,
        cmd.delayBetweenRepeatitions,
        cmd.delayAfterCommand
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

    WaitForItemCommand cmd(videoCapture, detector, 0, 0.98f);
    cmd.delayBeforeCommand = 50;
    cmd.delayAfterCommand = 50;
    cmd.delayBetweenRepeatitions = 100;
    cmd.waitForExists = false;

    histories.record("---");
    cmd.execute();
    histories.record("---");

    Assert::IsTrue(histories[0].equals("---"));
    Assert::IsTrue(histories[1].equals("takeSnapshot"));
    Assert::IsTrue(histories[2].equals("takeSnapshot"));
    Assert::IsTrue(histories[3].equals("takeSnapshot"));
    Assert::IsTrue(histories[4].equals("---"));

    histories.allDurationsAreInRange({
        cmd.delayBeforeCommand,
        cmd.delayBetweenRepeatitions,
        cmd.delayBetweenRepeatitions,
        cmd.delayAfterCommand
        }, 40);
}
}  // namespace Command
}  // namespace AutoMacro
