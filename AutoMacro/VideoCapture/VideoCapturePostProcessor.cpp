#pragma once
#include "AutoMacro/Core/Core.h"
#include "VideoCapturePostProcessor.h"

namespace AutoMacro {
namespace Impl {
VideoCapturePostProcessor::VideoCapturePostProcessor(
    VideoCapture* capture,
    ImageProcessor* processor) :
    capture_(capture),
    processor_(processor) {
}

Image VideoCapturePostProcessor::takeSnapshot() {
    Image image = capture_->takeSnapshot();
    return processor_->process(image);
}
}  // namespace Impl
}  // namespace AutoMacro
