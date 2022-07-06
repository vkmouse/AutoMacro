#include "AutoMacro/Cv/ImageProcessor/ImageProcessor.h"

#include <memory>

#include "AutoMacro/Cv/ImageProcessor/BGRConverterProcessor.h"
#include "AutoMacro/Cv/ImageProcessor/CroppingProcessor.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<ImageProcessor> createBGRConverterProcessor() {
    return std::make_shared<Impl::BGRConverterProcessor>();
}

std::shared_ptr<ImageProcessor> createCroppingProcessor(
        int x, int y, int width, int height) {
    Rect region(x, y, width, height);
    return std::make_shared<Impl::CroppingProcessor>(region);
}

std::shared_ptr<ImageProcessor> createCroppingProcessor(Rect region) {
    return std::make_shared<Impl::CroppingProcessor>(region);
}
}  // namespace Factory
}  // namespace AutoMacro
