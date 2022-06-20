#pragma once
#include <string>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Cv {
Image imread(std::string filename);
Image cropping(const Image& image, Rect region);
Image convertToBGR(const Image& image);
}  // namespace Cv
}  // namespace AutoMacro
