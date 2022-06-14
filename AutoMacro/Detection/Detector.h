#pragma once
#include <string>
#include <vector>

#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/Image.h"
#include "AutoMacro/Detection/DetectionResult.h"

namespace AutoMacro {
namespace Detection {
class DLL_EXPORTS Detector {
 public:
    Detector(Detector&& other) = default;
    Detector(const Detector&) = delete;

    Detector& operator=(Detector&& other) = default;
    Detector& operator=(const Detector&) = delete;

    virtual ~Detector() {}

    virtual void init() = 0;
    virtual DetectionResults detect(Image image) = 0;

 protected:
    Detector() {}
};
}  // namespace Detection

namespace Factory {
DLL_EXPORTS Detection::Detector* createTemplateBasedDetector(
    std::vector<std::string> imagesPath);
}  // namespace Factory
}  // namespace AutoMacro
