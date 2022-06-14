#include "AutoMacro/VideoCapture/CroppingProcessor.h"

#include "AutoMacro/Core/Cv.h"
#include "AutoMacro/Core/Image.h"
#include "AutoMacro/Core/Types.h"
#include "AutoMacro/Core/VideoCapture.h"
#include "AutoMacro/VideoCapture/VideoCapturePostProcessor.h"

namespace AutoMacro {
namespace Impl {
CroppingProcessor::CroppingProcessor(
    VideoCapture* videoCapture,
    int x, int y, int width, int height) :
    VideoCapturePostProcessor(videoCapture),
    region(x, y, width, height) {
}

CroppingProcessor::CroppingProcessor(
    VideoCapture* videoCapture,
    Rect region) :
    VideoCapturePostProcessor(videoCapture),
    region(region) {
}

Image CroppingProcessor::process(const Image& src) {
    return Cv::cropping(src, region);
}
}  //  namespace Impl
}  //  namespace AutoMacro
