#include "AutoMacro/VideoCapture/VideoCapture.h"

#include <string>
#include <vector>

#include "AutoMacro/VideoCapture/VideoCapture/ImageFileCapture.h"
#include "AutoMacro/VideoCapture/VideoCapture/VideoCapturePostProcessor.h"

namespace AutoMacro {
namespace Factory {
VideoCapture* createImageFileCapture(std::vector<std::string> filenames) {
    return new Impl::ImageFileCapture(filenames);
}

VideoCapture* addPostprocessing(
    VideoCapture* videoCapture,
    ImageProcessor* processor) {
    return new Impl::VideoCapturePostProcessor(videoCapture, processor);
}
}  // namespace Factory
}  // namespace AutoMacro
