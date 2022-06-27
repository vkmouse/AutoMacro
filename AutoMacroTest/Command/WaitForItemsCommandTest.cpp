#include "AutoMacroTest/Command/WaitForItemsCommandTest.h"

#include <memory>

#include "AutoMacro/Command/Command.h"
#include "AutoMacro/Detection/Detection.h"
#include "AutoMacro/History/History.h"
#include "AutoMacro/VideoCapture/VideoCapture.h"
#include "CppUnitTest.h"

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

    auto detector1 = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\Template_5x5_24bits.png" });
    auto detector2 = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\BlackWithWhiteBorder_5x5_24bits.png" });

    WaitForItemsCommandParameter p(
        videoCapture,
        { detector1, detector2 },
        { 0, 0 },
        { 0.98f, 0.98f });

    p.delayBeforeCommand = 50;
    p.delayAfterCommand = 50;
    p.delayBetweenRepeatitions = 100;
    p.waitForExists = true;
    p.waitForAllItems = true;

    auto cmd = Factory::createCommand(&p);

    histories.record("---");
    cmd->execute();
    histories.record("---");

    Assert::IsTrue(histories[0].equals("---"));
    Assert::IsTrue(histories[1].equals("takeSnapshot"));
    Assert::IsTrue(histories[2].equals("takeSnapshot"));
    Assert::IsTrue(histories[3].equals("takeSnapshot"));
    Assert::IsTrue(histories[4].equals("---"));

    bool allDurationsAreInRange = histories.allDurationsAreInRange({
        p.delayBeforeCommand,
        p.delayBetweenRepeatitions,
        p.delayBetweenRepeatitions,
        p.delayAfterCommand
        }, 40);
    Assert::IsTrue(allDurationsAreInRange);
}

void WaitForItemsCommandTest::TestWaitForAtLeastOneItem() {
    auto videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\ItemNotExists_10x10_24bits.png",
        "images\\AutoMacroTest\\ItemExists_10x10_24bits.png",
        "images\\AutoMacroTest\\AllItemExists_10x10_24bits.png" });

    History::Histories histories;
    videoCapture = Factory::addHistoryAgent(
        videoCapture, &histories);

    auto detector1 = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\Template_5x5_24bits.png" });
    auto detector2 = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\BlackWithWhiteBorder_5x5_24bits.png" });

    WaitForItemsCommandParameter p(
        videoCapture,
        { detector1, detector2 },
        { 0, 0 },
        { 0.98f, 0.98f });

    p.delayBeforeCommand = 50;
    p.delayAfterCommand = 50;
    p.delayBetweenRepeatitions = 100;
    p.waitForExists = true;
    p.waitForAllItems = false;

    auto cmd = Factory::createCommand(&p);

    histories.record("---");
    cmd->execute();
    histories.record("---");
    cmd->execute();
    histories.record("---");

    Assert::IsTrue(histories[0].equals("---"));
    Assert::IsTrue(histories[1].equals("takeSnapshot"));
    Assert::IsTrue(histories[2].equals("takeSnapshot"));
    Assert::IsTrue(histories[3].equals("---"));
    Assert::IsTrue(histories[4].equals("takeSnapshot"));
    Assert::IsTrue(histories[5].equals("---"));

    bool allDurationsAreInRange = histories.allDurationsAreInRange({
        p.delayBeforeCommand,
        p.delayBetweenRepeatitions,
        p.delayAfterCommand,
        p.delayBeforeCommand,
        p.delayAfterCommand
        }, 40);
    Assert::IsTrue(allDurationsAreInRange);
}
}  // namespace Command
}  // namespace AutoMacro
