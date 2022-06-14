#pragma once
#include <memory>
#include <string>
#include <vector>

#include "AutoMacro/Detection/DetectionResult.h"
#include "AutoMacro/Detection/Detector.h"

namespace AutoMacro {
namespace Detection {
namespace Impl {
class TemplateBasedDetector : public Detector {
 public:
    DLL_EXPORTS TemplateBasedDetector(std::vector<std::string> imagesPath);

    DLL_EXPORTS void init() override;
    DLL_EXPORTS DetectionResults detect(Image image) override;

 private:
    class Impl;
    std::unique_ptr<Impl> impl;
};
}  // namespace Impl
}  // namespace Detection
}  // namespace AutoMacro
