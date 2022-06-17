#include "AutoMacro/ImageProcessor/ImageProcessor/BGRConverterProcessor.h"

#include "AutoMacro/Core/Cv.h"
#include "AutoMacro/Core/Image.h"

namespace AutoMacro {
namespace Impl {
Image BGRConverterProcessor::process(const Image& src) {
    return Cv::convertToBGR(src);
}
}  // namespace Impl
}  // namespace AutoMacro
