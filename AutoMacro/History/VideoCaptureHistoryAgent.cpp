#include "AutoMacro/History/VideoCaptureHistoryAgent.h"

#include "AutoMacro/Core/Image.h"

namespace AutoMacro {
namespace History {
namespace Impl {
VideoCaptureHistoryAgent::VideoCaptureHistoryAgent(
    VideoCapture* videoCapture,
    Histories* histories) :
    videoCapture(videoCapture),
    histories(histories) {
}

Image VideoCaptureHistoryAgent::takeSnapshot() {
    Image image = videoCapture->takeSnapshot();
    histories->record("takeSnapshot");
    return image;
}
}  // namespace Impl
}  // namespace History
}  // namespace AutoMacro
