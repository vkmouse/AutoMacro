#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/History/History/Histories.h"

namespace AutoMacro {
namespace History {
namespace Impl {
class VideoCaptureHistoryAgent : public VideoCapture {
 public:
    VideoCaptureHistoryAgent(std::shared_ptr<VideoCapture> videoCapture, Histories* histories);

    virtual Image takeSnapshot();

 private:
    std::shared_ptr<VideoCapture> videoCapture;
    Histories* histories;
};
}  // namespace Impl
}  // namespace History
}  // namespace AutoMacro
