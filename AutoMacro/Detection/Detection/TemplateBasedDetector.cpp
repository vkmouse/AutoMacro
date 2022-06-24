#include "AutoMacro/Detection/Detection/TemplateBasedDetector.h"

#include <stdexcept>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Detection/Detection/DetectionResult.h"
#include "AutoMacro/Detection/Detection/DetectorParameter.h"

namespace AutoMacro {
namespace Detection {
namespace Impl {
TemplateBasedDetector::TemplateBasedDetector(
    std::vector<TemplateBasedDetectorParameter> parameters,
    int numBoxes) :
    numBoxes_(numBoxes) {
    imagesPath_.reserve(parameters.size());
    masksPath_.reserve(parameters.size());
    for (const auto& parameter : parameters) {
        imagesPath_.push_back(parameter.imagePath);
        masksPath_.push_back(parameter.maskPath);
    }
}

void TemplateBasedDetector::init() {
    for (const auto& path : imagesPath_) {
        cv::Mat templ = cv::imread(path);
        if (templ.empty()) {
            throw std::runtime_error("load image failed");
        }
        templates_.push_back(templ);
    }

    for (const auto& path : masksPath_) {
        cv::Mat mask = cv::Mat();
        if (!path.empty()) {
            mask = cv::imread(path);
            if (mask.empty()) {
                throw std::runtime_error("load image failed");
            }
        }
        masks_.push_back(mask);
    }
}

DetectionResults TemplateBasedDetector::detect(cv::Mat image) {
    DetectionResults results;
    for (int i = 0; i < templates_.size(); i++) {
        cv::Mat templ = templates_[i];
        cv::Mat mask = masks_[i];

        if (templ.type() != image.type()) {
            throw(std::runtime_error(
                "image type and template type are not equal"));
        }

        cv::Mat resultMap = matchTemplate(image, templ, mask);

        for (int i = 0; i < numBoxes_; i++) {
            DetectionResult result = getPartOfResult(resultMap);
            result.index = i;
            result.width = templ.cols;
            result.height = templ.rows;
            results.push_back(result);

            resultMap.at<float>(result.y, result.x) = 0;
        }
    }

    return results;
}

cv::Mat TemplateBasedDetector::matchTemplate(
    cv::InputArray image, cv::InputArray templ, cv::Mat mask) {
    cv::Mat map;
    if (mask.empty()) {
        cv::matchTemplate(image, templ, map, method);
    } else {
        cv::matchTemplate(image, templ, map, method, mask);
    }

    return map;
}

DetectionResult TemplateBasedDetector::getPartOfResult(cv::InputArray src) {
    cv::Point location;
    double confidence = 0;
    if (method == cv::TemplateMatchModes::TM_CCOEFF_NORMED) {
        cv::minMaxLoc(src, nullptr, &confidence, nullptr, &location);
    }

    DetectionResult result;
    result.confidence = static_cast<float>(confidence);
    result.x = location.x;
    result.y = location.y;

    return result;
}
}  // namespace Impl
}  // namespace Detection
}  // namespace AutoMacro
