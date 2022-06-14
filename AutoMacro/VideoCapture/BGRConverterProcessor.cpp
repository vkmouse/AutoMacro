#include "AutoMacro/VideoCapture/BGRConverterProcessor.h"

#include "AutoMacro/Core/Cv.h"
#include "AutoMacro/Core/Image.h"
#include "AutoMacro/VideoCapture/VideoCapturePostProcessor.h"

namespace AutoMacro {
namespace Impl {
Image BGRConverterProcessor::process(const Image& src) {
    return Cv::convertToBGR(src);
}
}  // namespace Impl
}  // namespace AutoMacro
