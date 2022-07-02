#pragma once
#include <memory>
#include <string>
#include <vector>
#include <utility>

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Cv/Detection/BaseDetector.h"

namespace AutoMacro {
namespace Impl {
class TemplateBasedDetector : public BaseDetector {
 public:
    TemplateBasedDetector(
        std::vector<std::pair<std::string, std::string>> templateAndMaskPaths,
        int numBoxes);

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
    int numBoxes_;
};
}  // namespace Impl
}  // namespace AutoMacro
