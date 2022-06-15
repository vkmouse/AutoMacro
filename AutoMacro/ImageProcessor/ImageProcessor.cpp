#include "AutoMacro/ImageProcessor/ImageProcessor.h"

#include "AutoMacro/Core/Types.h"
#include "AutoMacro/ImageProcessor/BGRConverterProcessor.h"
#include "AutoMacro/ImageProcessor/CroppingProcessor.h"

namespace AutoMacro {
namespace Factory {
ImageProcessor* createBGRConverterProcessor() {
    return new Impl::BGRConverterProcessor();
}

ImageProcessor* createCroppingProcessor(int x, int y, int width, int height) {
    Rect region(x, y, width, height);
    return createCroppingProcessor(region);
}

ImageProcessor* createCroppingProcessor(Rect region) {
    return new Impl::CroppingProcessor(region);
}
}  // namespace Factory
}  // namespace AutoMacro
