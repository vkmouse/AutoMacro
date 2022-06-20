#pragma once
#include "AutoMacro/VideoCapture/VideoCapture/VideoCapturePostProcessor.h"

#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Impl {
VideoCapturePostProcessor::VideoCapturePostProcessor(
    std::shared_ptr<VideoCapture> capture,
    std::shared_ptr<ImageProcessor> processor) :
    capture_(capture),
    processor_(processor) {
}

Image VideoCapturePostProcessor::takeSnapshot() {
    Image image = capture_->takeSnapshot();
    return processor_->process(image);
}
}  // namespace Impl
}  // namespace AutoMacro
