#include "AutoMacroTest/Command/WaitForItemCommandTest.h"

#include <AutoMacro/Command/WaitForItemCommand.h>
#include <AutoMacro/History/History.h>
#include <AutoMacro/History/HistoryAgent.h>
#include <AutoMacro/VideoCapture/VideoCapture.h>
#include "AutoMacroTest/History/HistoryAssert.h"

namespace AutoMacro {
namespace Command {
namespace {
using History::HistoryAssert;
}  // namespace

void WaitForItemCommandTest::TestWaitForItemCommand() {
    History::Histories histories;
    VideoCapture* videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\ItemNotExists_10x10_24bits.png",
        "images\\AutoMacroTest\\ItemNotExists_10x10_24bits.png",
        "images\\AutoMacroTest\\ItemExists_10x10_24bits.png"
    });
    videoCapture = Factory::addVideoCaptureHistoryAgent(
        videoCapture, &histories);

    Detection::Detector* detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTest\\Template_5x5_24bits.png",
    });

    WaitForItemCommandParameter p(detector, 0, 0.98f);
    p.delayBetweenRepeatitions = 100;
    p.waitForExists = true;
    int tolerence = 40;

    Command* command = new WaitForItemCommand(videoCapture, p);
    histories.record("---");
    command->execute();
    histories.record("---");

    HistoryAssert::areEqual(histories[0], "---");
    HistoryAssert::areEqual(histories[1], "takeSnapshot");
    HistoryAssert::areEqual(histories[2], "takeSnapshot");
    HistoryAssert::areEqual(histories[3], "takeSnapshot");
    HistoryAssert::areEqual(histories[4], "---");

    HistoryAssert::durationIsInRange(histories[0], histories[4],
        p.delayBetweenRepeatitions * 2,
        p.delayBetweenRepeatitions * 2 + tolerence);
    delete(command);
}
}  // namespace Command
}  // namespace AutoMacro
