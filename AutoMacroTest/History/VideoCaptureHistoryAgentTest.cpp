#include "AutoMacroTest/History/VideoCaptureHistoryAgentTest.h"

#include "CppUnitTest.h"
#include <AutoMacro/History/History.h>
#include <AutoMacro/VideoCapture/VideoCapture.h>
#include "AutoMacroTest/History/HistoryAssert.h"

namespace AutoMacro {
namespace History {
void VideoCaptureHistoryAgentTest::TestVideoCaptureHistoryAgent() {
    Histories histories;
    VideoCapture* videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\Template_5x5_24bits.png"
    });
    videoCapture =
        Factory::addHistoryAgent(videoCapture, &histories);

    videoCapture->takeSnapshot();
    HistoryAssert::areEqual(histories.back(), "takeSnapshot");
}
}  // namespace History
}  // namespace AutoMacro
