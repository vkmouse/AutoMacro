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

    Detection::Detector* detector =
        new Detection::Impl::TemplateBasedDetector(imagesPath);
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
