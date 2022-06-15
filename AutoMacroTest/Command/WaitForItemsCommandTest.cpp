#include "AutoMacroTest/Command/WaitForItemsCommandTest.h"

#include <AutoMacro/Command/WaitForItemsCommand.h>
#include <AutoMacro/Detection/Detector.h>
#include <AutoMacro/History/History.h>
#include <AutoMacro/History/HistoryAgent.h>
#include <AutoMacro/VideoCapture/VideoCapture.h>
#include "AutoMacroTest/History/HistoryAssert.h"

namespace AutoMacro {
namespace Command {
namespace {
using History::HistoryAssert;
}  // namespace

void WaitForItemsCommandTest::TestWaitForAllItems() {
	VideoCapture* videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\ItemNotExists_10x10_24bits.png",
        "images\\AutoMacroTest\\ItemExists_10x10_24bits.png",
        "images\\AutoMacroTest\\AllItemExists_10x10_24bits.png" });

    History::Histories histories;
    videoCapture = Factory::addVideoCaptureHistoryAgent(
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

    HistoryAssert::areEqual(histories[0], "---");
    HistoryAssert::areEqual(histories[1], "takeSnapshot");
    HistoryAssert::areEqual(histories[2], "takeSnapshot");
    HistoryAssert::areEqual(histories[3], "takeSnapshot");
    HistoryAssert::areEqual(histories[4], "---");

    HistoryAssert::AllDurationAreInRange(histories, {
        cmd.delayBeforeCommand,
        cmd.delayBetweenRepeatitions,
        cmd.delayBetweenRepeatitions,
        cmd.delayAfterCommand
        }, 40);
}

void WaitForItemsCommandTest::TestWaitForAtLeastOneItem() {
    VideoCapture* videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\ItemNotExists_10x10_24bits.png",
        "images\\AutoMacroTest\\ItemExists_10x10_24bits.png",
        "images\\AutoMacroTest\\AllItemExists_10x10_24bits.png" });

    History::Histories histories;
    videoCapture = Factory::addVideoCaptureHistoryAgent(
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

    HistoryAssert::areEqual(histories[0], "---");
    HistoryAssert::areEqual(histories[1], "takeSnapshot");
    HistoryAssert::areEqual(histories[2], "takeSnapshot");
    HistoryAssert::areEqual(histories[3], "---");
    HistoryAssert::areEqual(histories[4], "takeSnapshot");
    HistoryAssert::areEqual(histories[5], "---");

    HistoryAssert::AllDurationAreInRange(histories, {
        cmd.delayBeforeCommand,
        cmd.delayBetweenRepeatitions,
        cmd.delayAfterCommand,
        cmd.delayBeforeCommand,
        cmd.delayAfterCommand
        }, 40);
}
}  // namespace Command
}  // namespace AutoMacro
