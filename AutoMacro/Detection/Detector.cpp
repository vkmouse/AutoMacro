#include "AutoMacro/Detection/Detector.h"

#include <stdexcept>
#include <string>
#include <vector>

#include "AutoMacro/Detection/DetectorPreprocessor.h"
#include "AutoMacro/Detection/TemplateBasedDetector.h"
#include "AutoMacro/ImageProcessor/ImageProcessor.h"

namespace AutoMacro {
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

Detection::Detector* addDetectorPreprocessing(
    Detection::Detector* detector,
    ImageProcessor* processor) {
    return new Detection::Impl::DetectorPreprocessor(detector, processor);
}
}  // namespace Factory
}  // namespace AutoMacro
