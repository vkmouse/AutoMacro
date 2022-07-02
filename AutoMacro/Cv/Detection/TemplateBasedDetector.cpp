#include "AutoMacro/Cv/Detection/TemplateBasedDetector.h"

#include <stdexcept>
#include <utility>

#include "opencv2/core.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Impl {
TemplateBasedDetector::TemplateBasedDetector(
    std::vector<std::pair<std::string, std::string>> templateAndMaskPaths,
    int numBoxes)
    : numBoxes_(numBoxes) {
    if (templateAndMaskPaths.size() == 0) {
        throw std::runtime_error{ "No image for template based detector" };
    }
    imagesPath_.reserve(templateAndMaskPaths.size());
    masksPath_.reserve(templateAndMaskPaths.size());
    for (const auto& templateAndMaskPath : templateAndMaskPaths) {
        imagesPath_.push_back(templateAndMaskPath.first);
        masksPath_.push_back(templateAndMaskPath.second);
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

        for (int j = 0; j < numBoxes_; j++) {
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
}  // namespace AutoMacro
