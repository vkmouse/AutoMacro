#pragma once
#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/Image.h"
#include "AutoMacro/Core/VideoCapture.h"

namespace AutoMacro {
class DLL_EXPORTS VideoCapturePostProcessor : public VideoCapture {
 public:
    explicit VideoCapturePostProcessor(VideoCapture* capture);

    Image takeSnapshot() override;

 protected:
    virtual Image process(const Image& src) = 0;

 private:
    VideoCapture* capture_;
};
}  // namespace AutoMacro
