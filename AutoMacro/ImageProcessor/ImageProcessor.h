#pragma once
#include "AutoMacro/Core/Core.h"
#include "AutoMacro/ImageProcessor/ImageProcessor/ImageProcessor.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS ImageProcessor* createBGRConverterProcessor();
DLL_EXPORTS ImageProcessor* createCroppingProcessor(
    int x, int y, int width, int height);
DLL_EXPORTS ImageProcessor* createCroppingProcessor(Rect region);
}  // namespace Factory
}  // namespace AutoMacro
