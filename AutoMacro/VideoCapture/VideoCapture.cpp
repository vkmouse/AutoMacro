#include "AutoMacro/VideoCapture/VideoCapture.h"

#include <string>
#include <vector>

#include "AutoMacro/VideoCapture/ImageFileCapture.h"
#include "AutoMacro/VideoCapture/BGRConverterProcessor.h"
#include "AutoMacro/VideoCapture/CroppingProcessor.h"

namespace AutoMacro {
namespace Factory {
VideoCapture* createImageFileCapture(std::vector<std::string> filenames) {
    return new Impl::ImageFileCapture(filenames);
}

VideoCapture* addBGRConverterProcessor(VideoCapture* videoCapture) {
    return new Impl::BGRConverterProcessor(videoCapture);
}

VideoCapture* addCroppingProcessor(VideoCapture* videoCapture,
    int x, int y, int width, int height) {
    return new Impl::CroppingProcessor(videoCapture, x, y, width, height);
}

VideoCapture* addCroppingProcessor(VideoCapture* videoCapture, Rect region) {
    return new Impl::CroppingProcessor(videoCapture, region);
}
}  // namespace Factory
}  // namespace AutoMacro
