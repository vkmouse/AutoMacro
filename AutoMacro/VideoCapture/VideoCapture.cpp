#include "AutoMacro/VideoCapture/VideoCapture.h"

#include <memory>
#include <string>
#include <vector>

#include "AutoMacro/VideoCapture/VideoCapture/DesktopCapture.h"
#include "AutoMacro/VideoCapture/VideoCapture/ImageFileCapture.h"
#include "AutoMacro/VideoCapture/VideoCapture/VideoCapturePostProcessor.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<VideoCapture> createDesktopCapture() {
    return std::make_shared<Impl::DesktopCapture>();
}

std::shared_ptr<VideoCapture> createImageFileCapture(
    std::vector<std::string> filenames) {
    return std::make_shared<Impl::ImageFileCapture>(filenames);
}

std::shared_ptr<VideoCapture> addPostprocessing(
    std::shared_ptr<VideoCapture> videoCapture,
    std::shared_ptr<ImageProcessor> processor) {
    return std::make_shared<Impl::VideoCapturePostProcessor>(
        videoCapture, processor);
}
}  // namespace Factory
}  // namespace AutoMacro
