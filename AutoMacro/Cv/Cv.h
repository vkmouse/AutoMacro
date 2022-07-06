#pragma once
#include <memory>
#include <string>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Cv/Command/Command.h"
#include "AutoMacro/Cv/Detection/Detection.h"
#include "AutoMacro/Cv/ImageProcessor/ImageProcessor.h"
#include "AutoMacro/Cv/Kvm/Kvm.h"

namespace AutoMacro {
namespace Cv {
DLL_EXPORTS Image imread(std::string filename);
DLL_EXPORTS Image cropping(const Image& image, Rect region);
DLL_EXPORTS Image convertToBGR(const Image& image);
}  // namespace Cv
}  // namespace AutoMacro
