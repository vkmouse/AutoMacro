#include "AutoMacro/Util/History/VideoCaptureHistoryAgent.h"

#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Util/History/Histories.h"

namespace AutoMacro {
namespace Impl {
VideoCaptureHistoryAgent::VideoCaptureHistoryAgent(
    std::shared_ptr<VideoCapture> videoCapture, Histories* histories)
    : videoCapture(videoCapture), histories(histories) {
}

Image VideoCaptureHistoryAgent::takeSnapshot() {
    Image image = videoCapture->takeSnapshot();
    histories->record("takeSnapshot");
    return image;
}

void VideoCaptureHistoryAgent::addPostprocessor(
        std::shared_ptr<ImageProcessor> processor) {
    videoCapture->addPostprocessor(processor);
}

void VideoCaptureHistoryAgent::removeLastPostprocessor() {
    videoCapture->removeLastPostprocessor();
}
}  // namespace Impl
}  // namespace AutoMacro
