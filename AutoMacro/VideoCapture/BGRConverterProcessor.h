#pragma once
#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/Image.h"
#include "AutoMacro/VideoCapture/VideoCapturePostProcessor.h"

namespace AutoMacro {
namespace Impl {
class DLL_EXPORTS BGRConverterProcessor : public VideoCapturePostProcessor {
 public:
    using VideoCapturePostProcessor::VideoCapturePostProcessor;

 protected:
    virtual Image process(const Image& src);
};
}  // namespace Impl
}  // namespace AutoMacro
