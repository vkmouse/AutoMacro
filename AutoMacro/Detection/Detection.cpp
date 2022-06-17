#include "AutoMacro/Detection/Detection.h"

#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

#include "AutoMacro/Detection/Detection/Detector.h"
#include "AutoMacro/Detection/Detection/DetectorParameter.h"
#include "AutoMacro/Detection/Detection/DetectionResult.h"
#include "AutoMacro/Detection/Detection/DetectorPreprocessor.h"
#include "AutoMacro/Detection/Detection/TemplateBasedDetector.h"
#include "AutoMacro/ImageProcessor/ImageProcessor.h"

namespace AutoMacro {
namespace Detection {
bool itemExists(const DetectionResults& results, int index, float threshold) {
    auto func = [&index, &threshold](const DetectionResult& item) {
        return item.index == index && item.confidence > threshold;
    };
    auto iterator = std::find_if(results.begin(), results.end(), func);
    bool found = iterator != results.end();
    return found;
}
}  // namespace Detection

namespace Factory {
Detection::Detector* createTemplateBasedDetector(
    std::vector<std::string> imagesPath) {
    if (imagesPath.size() == 0) {
        throw std::runtime_error{ "No image for template based detector" };
    }

    using Detection::TemplateBasedDetectorParameter;
    std::vector<TemplateBasedDetectorParameter> parameters;
    parameters.reserve(imagesPath.size());
    for (const auto& path : imagesPath) {
        parameters.push_back(TemplateBasedDetectorParameter(path));
    }

    Detection::Detector* detector =
        new Detection::Impl::TemplateBasedDetector(parameters);
    detector->init();

    return detector;
}

Detection::Detector* createTemplateBasedDetectorWithMask(
    std::vector<Detection::TemplateBasedDetectorParameter> parameters) {
    if (parameters.size() == 0) {
        throw std::runtime_error{ "No image for template based detector" };
    }

    Detection::Detector* detector =
        new Detection::Impl::TemplateBasedDetector(parameters);
    detector->init();

    return detector;
}

Detection::Detector* addPreprocessing(
    Detection::Detector* detector,
    ImageProcessor* processor) {
    return new Detection::Impl::DetectorPreprocessor(detector, processor);
}
}  // namespace Factory
}  // namespace AutoMacro
