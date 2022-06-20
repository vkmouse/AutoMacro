#pragma once
#include <memory>
#include <string>
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/ImageProcessor/ImageProcessor.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<VideoCapture> createImageFileCapture(
    std::vector<std::string> filenames);
DLL_EXPORTS std::shared_ptr<VideoCapture> addPostprocessing(
    std::shared_ptr<VideoCapture> videoCapture,
    std::shared_ptr<ImageProcessor> processor);
}  // namespace Factory
}  // namespace AutoMacro
