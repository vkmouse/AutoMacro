#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/ImageProcessor/ImageProcessor.h"

namespace AutoMacro {
namespace Impl {
class VideoCapturePostProcessor : public VideoCapture {
 public:
    VideoCapturePostProcessor(std::shared_ptr<VideoCapture> capture, ImageProcessor* processor);

    virtual Image takeSnapshot();

 private:
    std::shared_ptr<VideoCapture> capture_;
    ImageProcessor* processor_;
};
}  // namespace Impl
}  // namespace AutoMacro
