#pragma once
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Detector> createTemplateBasedDetector(
    std::vector<std::string> templatePaths, int numBoxes = 1);
DLL_EXPORTS std::shared_ptr<Detector> createTemplateBasedDetector(
    std::vector<std::pair<std::string, std::string>> templateAndMaskPaths,
    int numBoxes = 1);
DLL_EXPORTS std::shared_ptr<Detector> createNetworkBasedDetector(
    std::string modelName, std::string config, int width, int height);
}  // namespace Factory
}  // namespace AutoMacro
