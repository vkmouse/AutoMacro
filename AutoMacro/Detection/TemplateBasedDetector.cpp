#include "AutoMacro/Detection/TemplateBasedDetector.h"

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

namespace AutoMacro {
namespace Detection {
namespace Impl {
class TemplateBasedDetector::Impl {
 public:
    explicit Impl(std::vector<std::string> imagesPath) :
        imagesPath_(imagesPath) {
    }

    void readAllTemplates() {
        for (const auto& path : imagesPath_) {
            cv::Mat templ = cv::imread(path);
            if (templ.empty()) {
                throw std::runtime_error("load image failed");
            } else {
                templates_.push_back(templ);
            }
        }
    }

    DetectionResults detect(Image image) {
        int type;
        if (image.channel() == 1) {
            type = CV_8UC1;
        } else if (image.channel() == 3) {
            type = CV_8UC3;
        } else if (image.channel() == 4) {
            type = CV_8UC4;
        }
        cv::Mat input(image.height(), image.width(), type, image.data());

        DetectionResults output;
        for (int i = 0; i < templates_.size(); i++) {
            cv::Mat templ = templates_[i];
            cv::Mat result;
            cv::matchTemplate(
                input,
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

 private:
    std::vector<std::string> imagesPath_;
    std::vector<cv::Mat> templates_;
};

TemplateBasedDetector::TemplateBasedDetector(
    std::vector<std::string> imagesPath) :
    impl(new Impl(imagesPath)) {
}

void TemplateBasedDetector::init() {
    impl->readAllTemplates();
}

DetectionResults TemplateBasedDetector::detect(Image image) {
    return impl->detect(image);
}
}  // namespace Impl
}  // namespace Detection
}  // namespace AutoMacro
