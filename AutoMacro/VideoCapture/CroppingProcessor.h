#pragma once
#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/Image.h"
#include "AutoMacro/Core/Types.h"
#include "AutoMacro/VideoCapture/VideoCapturePostProcessor.h"

namespace AutoMacro {
namespace Impl {
class DLL_EXPORTS CroppingProcessor : public VideoCapturePostProcessor {
 public:
    CroppingProcessor(VideoCapture* videoCapture,
        int x, int y, int width, int height);
    CroppingProcessor(VideoCapture* videoCapture, Rect region);

 protected:
    virtual Image process(const Image& src);

 private:
     Rect region;
};
}  // namespace Impl
}  // namespace AutoMacro
