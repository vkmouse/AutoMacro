#pragma once
#include <memory>
#include <string>
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Detection/Detection/Detector.h"
#include "AutoMacro/Detection/Detection/DetectorParameter.h"
#include "AutoMacro/Detection/Detection/DetectionResult.h"
#include "AutoMacro/Detection/Detection/DetectionResults.h"
#include "AutoMacro/ImageProcessor/ImageProcessor.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Detection::Detector> createTemplateBasedDetector(
    std::vector<std::string> imagesPath, int numBoxes = 1);
DLL_EXPORTS std::shared_ptr<Detection::Detector> createTemplateBasedDetector(
    std::vector<Detection::TemplateBasedDetectorParameter> parameters,
    int numBoxes = 1);
DLL_EXPORTS std::shared_ptr<Detection::Detector> addPreprocessing(
    std::shared_ptr<Detection::Detector> detector,
    std::shared_ptr<ImageProcessor> processor);
}  // namespace Factory
}  // namespace AutoMacro
