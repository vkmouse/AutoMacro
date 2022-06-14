#pragma once
#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/Image.h"
#include "AutoMacro/History/History.h"
#include "AutoMacro/Core/VideoCapture.h"

namespace AutoMacro {
namespace History {
namespace Impl {
class DLL_EXPORTS VideoCaptureHistoryAgent : public VideoCapture {
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
