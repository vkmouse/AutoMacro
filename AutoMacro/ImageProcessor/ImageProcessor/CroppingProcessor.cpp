#include "AutoMacro/ImageProcessor/ImageProcessor/CroppingProcessor.h"

#include "AutoMacro/Core/Cv.h"
#include "AutoMacro/Core/Image.h"
#include "AutoMacro/Core/Types.h"

namespace AutoMacro {
namespace Impl {
CroppingProcessor::CroppingProcessor(Rect region) : region(region) {
}

Image CroppingProcessor::process(const Image& src) {
    return Cv::cropping(src, region);
}
}  //  namespace Impl
}  // namespace AutoMacro
