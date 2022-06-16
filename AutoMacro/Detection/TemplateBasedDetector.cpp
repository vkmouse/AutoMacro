#include "AutoMacro/Detection/TemplateBasedDetector.h"

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

namespace AutoMacro {
namespace Detection {
namespace Impl {
TemplateBasedDetector::TemplateBasedDetector(
    std::vector<std::string> imagesPath) :
    imagesPath_(imagesPath) {
}

void TemplateBasedDetector::init() {
    for (const auto& path : imagesPath_) {
        cv::Mat templ = cv::imread(path);
        if (templ.empty()) {
            throw std::runtime_error("load image failed");
        } else {
            templates_.push_back(templ);
        }
    }
}

DetectionResults TemplateBasedDetector::detect(cv::Mat image) {
    DetectionResults output;
    for (int i = 0; i < templates_.size(); i++) {
        cv::Mat templ = templates_[i];
        cv::Mat result;
        cv::matchTemplate(
            image,
            templ,
            result,
            cv::TemplateMatchModes::TM_CCOEFF_NORMED);

        double maxVal;
        cv::Point maxLoc;
        cv::minMaxLoc(result, nullptr, &maxVal, nullptr, &maxLoc);

        DetectionResult res(
            i,
            maxLoc.x,
            maxLoc.y,
            templ.cols,
            templ.rows,
            static_cast<float>(maxVal));
        output.push_back(res);
    }

    return output;
}
}  // namespace Impl
}  // namespace Detection
}  // namespace AutoMacro
