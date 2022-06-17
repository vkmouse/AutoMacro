#pragma once
#include <string>
#include <vector>

#include "AutoMacro/Core/pch.h"
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
DLL_EXPORTS Detection::Detector* createTemplateBasedDetector(
    std::vector<std::string> imagesPath);
DLL_EXPORTS Detection::Detector* createTemplateBasedDetectorWithMask(
    std::vector<Detection::TemplateBasedDetectorParameter> parameters);
DLL_EXPORTS Detection::Detector* addPreprocessing(
    Detection::Detector* detector, ImageProcessor* processor);
}  // namespace Factory
}  // namespace AutoMacro
