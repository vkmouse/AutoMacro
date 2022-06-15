#pragma once
#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/Image.h"
#include "AutoMacro/Core/Types.h"
#include "AutoMacro/ImageProcessor/ImageProcessor.h"

namespace AutoMacro {
namespace Impl {
class DLL_EXPORTS CroppingProcessor : public ImageProcessor {
 public:
    explicit CroppingProcessor(Rect region);

    virtual Image process(const Image& src);

 private:
    Rect region;
};
}  // namespace Impl
}  // namespace AutoMacro
