#include "AutoMacroTest/Command/WaitForItemsCommandTest.h"

#include <AutoMacro/Command/WaitForItemsCommand.h>
#include <AutoMacro/Detection/Detection.h>
#include <AutoMacro/History/History.h>
#include <AutoMacro/VideoCapture/VideoCapture.h>

namespace AutoMacro {
namespace Command {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

void WaitForItemsCommandTest::TestWaitForAllItems() {
    auto videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\ItemNotExists_10x10_24bits.png",
        "images\\AutoMacroTest\\ItemExists_10x10_24bits.png",
        "images\\AutoMacroTest\\AllItemExists_10x10_24bits.png" });

    History::Histories histories;
    videoCapture = Factory::addHistoryAgent(
        videoCapture, &histories);

    Detection::Detector* detector1 = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\Template_5x5_24bits.png" });
    Detection::Detector* detector2 = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\BlackWithWhiteBorder_5x5_24bits.png" });

    WaitForItemsCommand cmd(
        videoCapture,
        { detector1, detector2 },
        { 0, 0 },
        { 0.98f, 0.98f });

    cmd.delayBeforeCommand = 50;
    cmd.delayAfterCommand = 50;
    cmd.delayBetweenRepeatitions = 100;
    cmd.waitForExists = true;
    cmd.waitForAllItems = true;

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

void WaitForItemsCommandTest::TestWaitForAtLeastOneItem() {
    auto videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\ItemNotExists_10x10_24bits.png",
        "images\\AutoMacroTest\\ItemExists_10x10_24bits.png",
        "images\\AutoMacroTest\\AllItemExists_10x10_24bits.png" });

    History::Histories histories;
    videoCapture = Factory::addHistoryAgent(
        videoCapture, &histories);

    Detection::Detector* detector1 = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\Template_5x5_24bits.png" });
    Detection::Detector* detector2 = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\BlackWithWhiteBorder_5x5_24bits.png" });

    WaitForItemsCommand cmd(
        videoCapture,
        { detector1, detector2 },
        { 0, 0 },
        { 0.98f, 0.98f });

    cmd.delayBeforeCommand = 50;
    cmd.delayAfterCommand = 50;
    cmd.delayBetweenRepeatitions = 100;
    cmd.waitForExists = true;
    cmd.waitForAllItems = false;

    histories.record("---");
    cmd.execute();
    histories.record("---");
    cmd.execute();
    histories.record("---");

    Assert::IsTrue(histories[0].equals("---"));
    Assert::IsTrue(histories[1].equals("takeSnapshot"));
    Assert::IsTrue(histories[2].equals("takeSnapshot"));
    Assert::IsTrue(histories[3].equals("---"));
    Assert::IsTrue(histories[4].equals("takeSnapshot"));
    Assert::IsTrue(histories[5].equals("---"));

    histories.allDurationsAreInRange({
        cmd.delayBeforeCommand,
        cmd.delayBetweenRepeatitions,
        cmd.delayAfterCommand,
        cmd.delayBeforeCommand,
        cmd.delayAfterCommand
        }, 40);
}
}  // namespace Command
}  // namespace AutoMacro
