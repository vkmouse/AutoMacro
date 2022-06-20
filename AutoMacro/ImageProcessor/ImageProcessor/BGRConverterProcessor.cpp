#include "AutoMacro/ImageProcessor/ImageProcessor/BGRConverterProcessor.h"

#include "AutoMacro/Cv/Cv.h"
#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Impl {
Image BGRConverterProcessor::process(const Image& src) {
    return Cv::convertToBGR(src);
}
}  // namespace Impl
}  // namespace AutoMacro
