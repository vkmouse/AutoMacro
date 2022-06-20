#include "AutoMacroTest/History/VideoCaptureHistoryAgentTest.h"

#include "CppUnitTest.h"
#include <AutoMacro/History/History.h>
#include <AutoMacro/VideoCapture/VideoCapture.h>

namespace AutoMacro {
namespace History {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

void VideoCaptureHistoryAgentTest::TestVideoCaptureHistoryAgent() {
    Histories histories;
    auto videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTest\\Template_5x5_24bits.png"
    });
    videoCapture =
        Factory::addHistoryAgent(videoCapture, &histories);

    videoCapture->takeSnapshot();
    Assert::IsTrue(histories.back().equals("takeSnapshot"));
}
}  // namespace History
}  // namespace AutoMacro
