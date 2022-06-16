#pragma once
#include <memory>
#include <string>
#include <vector>

#include "AutoMacro/Detection/BaseDetector.h"
#include "AutoMacro/Detection/DetectionResult.h"

namespace AutoMacro {
namespace Detection {
namespace Impl {
class TemplateBasedDetector : public BaseDetector {
 public:
    explicit TemplateBasedDetector(std::vector<std::string> imagesPath);

    void init() override;

 protected:
    DetectionResults detect(cv::Mat image) override;

 private:
    std::vector<std::string> imagesPath_;
    std::vector<cv::Mat> templates_;
};
}  // namespace Impl
}  // namespace Detection
}  // namespace AutoMacro
