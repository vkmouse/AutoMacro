#include "AutoMacro/Detection/Detection.h"

#include <algorithm>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include "AutoMacro/Detection/Detection/Detector.h"
#include "AutoMacro/Detection/Detection/DetectorParameter.h"
#include "AutoMacro/Detection/Detection/TemplateBasedDetector.h"
#include "AutoMacro/ImageProcessor/ImageProcessor.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Detection::Detector> createTemplateBasedDetector(
    std::vector<std::string> imagesPath,
    int numBoxes) {
    using Detection::Detector;
    using Detection::TemplateBasedDetectorParameter;
    using Detection::Impl::TemplateBasedDetector;

    if (imagesPath.size() == 0) {
        throw std::runtime_error{ "No image for template based detector" };
    }

    std::vector<TemplateBasedDetectorParameter> parameters;
    parameters.reserve(imagesPath.size());
    for (const auto& path : imagesPath) {
        parameters.push_back(TemplateBasedDetectorParameter(path));
    }

    std::shared_ptr<Detector> detector =
        std::make_shared<TemplateBasedDetector>(parameters, numBoxes);
    detector->init();

    return detector;
}

std::shared_ptr<Detection::Detector> createTemplateBasedDetector(
    std::vector<Detection::TemplateBasedDetectorParameter> parameters,
    int numBoxes) {
    using Detection::Detector;
    using Detection::Impl::TemplateBasedDetector;

    if (parameters.size() == 0) {
        throw std::runtime_error{ "No image for template based detector" };
    }

    std::shared_ptr<Detector> detector =
        std::make_shared<TemplateBasedDetector>(parameters, numBoxes);
    detector->init();

    return detector;
}
}  // namespace Factory
}  // namespace AutoMacro
