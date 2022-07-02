#pragma once
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Cv/Command/WaitForItemCommandParameter.h"
#include "AutoMacro/Cv/Command/WaitForItemsCommandParameter.h"

namespace AutoMacro {
namespace Cv {
DLL_EXPORTS Image imread(std::string filename);
DLL_EXPORTS Image cropping(const Image& image, Rect region);
DLL_EXPORTS Image convertToBGR(const Image& image);
}  // namespace Cv

namespace Factory {
DLL_EXPORTS std::shared_ptr<VideoCapture> createImageFileCapture(
    std::vector<std::string> filenames);

DLL_EXPORTS std::shared_ptr<ImageProcessor> createBGRConverterProcessor();
DLL_EXPORTS std::shared_ptr<ImageProcessor> createCroppingProcessor(
    int x, int y, int width, int height);
DLL_EXPORTS std::shared_ptr<ImageProcessor> createCroppingProcessor(
    Rect region);

DLL_EXPORTS std::shared_ptr<Detector> createTemplateBasedDetector(
    std::vector<std::string> templatePaths, int numBoxes = 1);
DLL_EXPORTS std::shared_ptr<Detector> createTemplateBasedDetector(
    std::vector<std::pair<std::string, std::string>> templateAndMaskPaths,
    int numBoxes = 1);

DLL_EXPORTS std::shared_ptr<Command> createCommand(
    WaitForItemCommandParameter* parameter);
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    WaitForItemsCommandParameter* parameter);
}  // namespace Factory
}  // namespace AutoMacro
