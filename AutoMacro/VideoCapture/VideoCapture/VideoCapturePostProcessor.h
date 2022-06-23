#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/ImageProcessor/ImageProcessor.h"

namespace AutoMacro {
namespace Impl {
class VideoCapturePostProcessor : public VideoCapture {
 public:
    VideoCapturePostProcessor(
        std::shared_ptr<VideoCapture> capture,
        std::shared_ptr<ImageProcessor> processor);

    virtual Image takeSnapshot();

 private:
    std::shared_ptr<VideoCapture> capture_;
    std::shared_ptr<ImageProcessor> processor_;
};
}  // namespace Impl
}  // namespace AutoMacro
