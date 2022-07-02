#include "AutoMacro/Cv/ImageProcessor/CroppingProcessor.h"

#include "AutoMacro/Cv/Cv.h"
#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Impl {
CroppingProcessor::CroppingProcessor(Rect region) : region(region) {
}

Image CroppingProcessor::process(const Image& src) {
    return Cv::cropping(src, region);
}
}  //  namespace Impl
}  // namespace AutoMacro
