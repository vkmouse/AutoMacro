#pragma once
#include <string>

namespace AutoMacro {
namespace Detection {
struct TemplateBasedDetectorParameter {
    explicit TemplateBasedDetectorParameter(std::string imagePath) :
        imagePath(imagePath) {}

    TemplateBasedDetectorParameter(
        std::string imagePath,
        std::string maskPath) :
        imagePath(imagePath),
        maskPath(maskPath) {}

    std::string imagePath;
    std::string maskPath;
};
}  // namespace Detection
}  // namespace AutoMacro
