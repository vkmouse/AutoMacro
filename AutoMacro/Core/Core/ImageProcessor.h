#pragma once
#include "AutoMacro/Core/Core/pch.h"
#include "AutoMacro/Core/Core/Image.h"

namespace AutoMacro {
class DLL_EXPORTS ImageProcessor {
 public:
    virtual Image process(const Image& src) = 0;

 protected:
     ImageProcessor() = default;
};
}  // namespace AutoMacro
