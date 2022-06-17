#pragma once
#include <string>
#include <vector>

#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/Types.h"
#include "AutoMacro/Core/VideoCapture.h"
#include "AutoMacro/ImageProcessor/ImageProcessor.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS VideoCapture* createImageFileCapture(
    std::vector<std::string> filenames);
DLL_EXPORTS VideoCapture* addVideoCapturePostprocessing(
    VideoCapture* videoCapture, ImageProcessor* processor);
}  // namespace Factory
}  // namespace AutoMacro
