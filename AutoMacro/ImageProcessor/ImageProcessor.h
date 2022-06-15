#pragma once
#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/Image.h"
#include "AutoMacro/Core/Types.h"

namespace AutoMacro {
class DLL_EXPORTS ImageProcessor {
 public:
    virtual Image process(const Image& src) = 0;

 protected:
     ImageProcessor() = default;
};

namespace Factory {
DLL_EXPORTS ImageProcessor* createBGRConverterProcessor();
DLL_EXPORTS ImageProcessor* createCroppingProcessor(
    int x, int y, int width, int height);
DLL_EXPORTS ImageProcessor* createCroppingProcessor(Rect region);
}  // namespace Factory
}  // namespace AutoMacro
