#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Util/History/Histories.h"

namespace AutoMacro {
namespace Impl {
class VideoCaptureHistoryAgent : public VideoCapture {
 public:
    VideoCaptureHistoryAgent(std::shared_ptr<VideoCapture> videoCapture,
                             Histories* histories);

    virtual Image takeSnapshot();

    void addPostprocessor(std::shared_ptr<ImageProcessor> processor) override;
    void removeLastPostprocessor() override;

 private:
    std::shared_ptr<VideoCapture> videoCapture;
    Histories* histories;
};
}  // namespace Impl
}  // namespace AutoMacro
