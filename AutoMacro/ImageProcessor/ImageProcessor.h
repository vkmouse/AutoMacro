#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/ImageProcessor/ImageProcessor/ImageProcessor.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<ImageProcessor> createBGRConverterProcessor();
DLL_EXPORTS std::shared_ptr<ImageProcessor> createCroppingProcessor(
    int x, int y, int width, int height);
DLL_EXPORTS std::shared_ptr<ImageProcessor> createCroppingProcessor(
    Rect region);
}  // namespace Factory
}  // namespace AutoMacro
