#pragma once
#include "AutoMacro/Core/Core.h"
#include "AutoMacro/ImageProcessor/ImageProcessor/ImageProcessor.h"

namespace AutoMacro {
namespace Impl {
class BGRConverterProcessor : public ImageProcessor {
 public:
    virtual Image process(const Image& src);
};
}  // namespace Impl
}  // namespace AutoMacro
