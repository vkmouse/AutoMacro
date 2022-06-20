#pragma once
#include <memory>
#include <string>
#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Detection/Detection/BaseDetector.h"
#include "AutoMacro/Detection/Detection/DetectionResult.h"
#include "AutoMacro/Detection/Detection/DetectorParameter.h"

namespace AutoMacro {
namespace Detection {
namespace Impl {
class TemplateBasedDetector : public BaseDetector {
 public:
    explicit TemplateBasedDetector(
        std::vector<TemplateBasedDetectorParameter> parameters);

    void init() override;

 protected:
    DetectionResults detect(cv::Mat image) override;

 private:
     cv::Mat matchTemplate(
        cv::InputArray image,
        cv::InputArray templ,
        cv::Mat mask);

    DetectionResult getPartOfResult(cv::InputArray src);

    int method = cv::TemplateMatchModes::TM_CCOEFF_NORMED;
    std::vector<std::string> imagesPath_;
    std::vector<std::string> masksPath_;
    std::vector<cv::Mat> templates_;
    std::vector<cv::Mat> masks_;
};
}  // namespace Impl
}  // namespace Detection
}  // namespace AutoMacro
