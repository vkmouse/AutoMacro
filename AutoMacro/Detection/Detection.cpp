#include "AutoMacro/Detection/Detection.h"

#include <algorithm>
#include <memory>
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

bool itemExists(const DetectionResults& results, float threshold) {
    auto func = [&threshold](const DetectionResult& item) {
        return item.confidence > threshold;
    };
    auto iterator = std::find_if(results.begin(), results.end(), func);
    bool found = iterator != results.end();
    return found;
}
}  // namespace Detection

namespace Factory {
std::shared_ptr<Detection::Detector> createTemplateBasedDetector(
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

    std::shared_ptr<Detection::Detector> detector =
        std::make_shared<Detection::Impl::TemplateBasedDetector>(parameters);
    detector->init();

    return detector;
}

std::shared_ptr<Detection::Detector> createTemplateBasedDetectorWithMask(
    std::vector<Detection::TemplateBasedDetectorParameter> parameters) {
    if (parameters.size() == 0) {
        throw std::runtime_error{ "No image for template based detector" };
    }

    std::shared_ptr<Detection::Detector> detector =
        std::make_shared<Detection::Impl::TemplateBasedDetector>(parameters);
    detector->init();

    return detector;
}

std::shared_ptr<Detection::Detector> addPreprocessing(
    std::shared_ptr<Detection::Detector> detector,
    std::shared_ptr<ImageProcessor> processor) {
    return std::make_shared<Detection::Impl::DetectorPreprocessor>(detector, processor);
}
}  // namespace Factory
}  // namespace AutoMacro
