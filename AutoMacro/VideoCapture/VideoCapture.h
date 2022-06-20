#pragma once
#include <string>
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/ImageProcessor/ImageProcessor.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS VideoCapture* createImageFileCapture(
    std::vector<std::string> filenames);
DLL_EXPORTS VideoCapture* addPostprocessing(
    VideoCapture* videoCapture, ImageProcessor* processor);
}  // namespace Factory
}  // namespace AutoMacro
