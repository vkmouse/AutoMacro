#pragma once
#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Impl {
class BGRConverterProcessor : public ImageProcessor {
 public:
    virtual Image process(const Image& src);
};
}  // namespace Impl
}  // namespace AutoMacro
