#pragma once
#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/Image.h"
#include "AutoMacro/ImageProcessor/ImageProcessor.h"

namespace AutoMacro {
namespace Impl {
class DLL_EXPORTS BGRConverterProcessor : public ImageProcessor {
 public:
    virtual Image process(const Image& src);
};
}  // namespace Impl
}  // namespace AutoMacro
