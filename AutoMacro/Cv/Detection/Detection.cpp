#include "AutoMacro/Cv/Detection/Detection.h"

#include <string>
#include <utility>
#include <vector>

#include "AutoMacro/Cv/Detection/NetworkBasedDetector.h"
#include "AutoMacro/Cv/Detection/TemplateBasedDetector.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Detector> createTemplateBasedDetector(
    std::vector<std::string> templatePaths, int numBoxes) {
    std::vector<std::pair<std::string, std::string>> templateAndMaskPaths;
    for (const auto& templatePath : templatePaths) {
        templateAndMaskPaths.push_back({ templatePath, "" });
    }
    auto detector = std::make_shared<Impl::TemplateBasedDetector>(
        templateAndMaskPaths, numBoxes);
    detector->init();
    return detector;
}

std::shared_ptr<Detector> createTemplateBasedDetector(
    std::vector<std::pair<std::string, std::string>> templateAndMaskPaths,
    int numBoxes) {
    auto detector = std::make_shared<Impl::TemplateBasedDetector>(
        templateAndMaskPaths, numBoxes);
    detector->init();
    return detector;
}

std::shared_ptr<Detector> createNetworkBasedDetector(
    std::string modelName, std::string config, int width, int height) {
    auto detector = std::make_shared<Impl::NetworkBasedDetector>(
        modelName, config, width, height);
    detector->init();
    return detector;
}
}  // namespace Factory
}  // namespace AutoMacro
