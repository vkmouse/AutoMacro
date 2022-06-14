#pragma once
#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/Image.h"
#include "AutoMacro/Core/VideoCapture.h"
#include "VideoCapturePostProcessor.h"

namespace AutoMacro {
VideoCapturePostProcessor::VideoCapturePostProcessor(VideoCapture* capture) :
    capture_(capture) {
}

Image VideoCapturePostProcessor::takeSnapshot() {
    Image image = capture_->takeSnapshot();
    return process(image);
}
}  // namespace AutoMacro
