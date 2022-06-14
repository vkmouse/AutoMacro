#pragma once
#include <string>
#include <vector>

#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/Types.h"
#include "AutoMacro/Core/VideoCapture.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS VideoCapture* createImageFileCapture(
    std::vector<std::string> filenames);
DLL_EXPORTS VideoCapture* addBGRConverterProcessor(
    VideoCapture* videoCapture);
DLL_EXPORTS VideoCapture* addCroppingProcessor(
    VideoCapture* videoCapture, int x, int y, int width, int height);
DLL_EXPORTS VideoCapture* addCroppingProcessor(
    VideoCapture* videoCapture, Rect region);
}  // namespace Factory
}  // namespace AutoMacro
