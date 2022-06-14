#include "AutoMacro/Detection/Detector.h"

#include <stdexcept>
#include <string>
#include <vector>

#include "AutoMacro/Detection/TemplateBasedDetector.h"

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
}  // namespace Factory
}  // namespace AutoMacro
