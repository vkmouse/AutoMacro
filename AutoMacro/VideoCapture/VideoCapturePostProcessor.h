#pragma once
#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/Image.h"
#include "AutoMacro/Core/VideoCapture.h"
#include "AutoMacro/ImageProcessor/ImageProcessor.h"

namespace AutoMacro {
namespace Impl {
class DLL_EXPORTS VideoCapturePostProcessor : public VideoCapture {
 public:
    VideoCapturePostProcessor(VideoCapture* capture, ImageProcessor* processor);

    virtual Image takeSnapshot();

 private:
    VideoCapture* capture_;
    ImageProcessor* processor_;
};
}  // namespace Impl
}  // namespace AutoMacro
