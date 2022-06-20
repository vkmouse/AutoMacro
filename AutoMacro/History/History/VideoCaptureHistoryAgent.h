#pragma once
#include "AutoMacro/Core/Core.h"
#include "AutoMacro/History/History/Histories.h"

namespace AutoMacro {
namespace History {
namespace Impl {
class VideoCaptureHistoryAgent : public VideoCapture {
 public:
    VideoCaptureHistoryAgent(VideoCapture* videoCapture, Histories* histories);

    virtual Image takeSnapshot();

 private:
    VideoCapture* videoCapture;
    Histories* histories;
};
}  // namespace Impl
}  // namespace History
}  // namespace AutoMacro
