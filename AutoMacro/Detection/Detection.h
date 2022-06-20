#pragma once
#include <memory>
#include <string>
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Detection/Detection/Detector.h"
#include "AutoMacro/Detection/Detection/DetectorParameter.h"
#include "AutoMacro/Detection/Detection/DetectionResult.h"
#include "AutoMacro/ImageProcessor/ImageProcessor.h"

namespace AutoMacro {
namespace Detection {
DLL_EXPORTS bool itemExists(
    const DetectionResults& results,
    int index,
    float threshold);

DLL_EXPORTS bool itemExists(
    const DetectionResults& results,
    float threshold);
}  // namespace Detection

namespace Factory {
DLL_EXPORTS std::shared_ptr<Detection::Detector> createTemplateBasedDetector(
    std::vector<std::string> imagesPath);
DLL_EXPORTS std::shared_ptr<Detection::Detector> createTemplateBasedDetectorWithMask(
    std::vector<Detection::TemplateBasedDetectorParameter> parameters);
DLL_EXPORTS std::shared_ptr<Detection::Detector> addPreprocessing(
    std::shared_ptr<Detection::Detector> detector, std::shared_ptr<ImageProcessor> processor);
}  // namespace Factory
}  // namespace AutoMacro
