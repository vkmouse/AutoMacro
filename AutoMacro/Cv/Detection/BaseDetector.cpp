#include "AutoMacro/Cv/Detection/BaseDetector.h"

#include "opencv2/core.hpp"
#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Impl {
DetectionResults BaseDetector::detect(Image image) {
    for (const auto& processor : preprocessors) {
        image = processor->process(image);
    }
    cv::Mat mat = imageToMat(image);
    return detect(mat);
}

void BaseDetector::addPreprocessor(std::shared_ptr<ImageProcessor> processor) {
    preprocessors.push_back(processor);
}

void BaseDetector::removeLastPreprocessor() {
    preprocessors.pop_back();
}

cv::Mat BaseDetector::imageToMat(const Image& image) {
    int type = 0;
    if (image.channel() == 1) {
        type = CV_8UC1;
    } else if (image.channel() == 3) {
        type = CV_8UC3;
    } else if (image.channel() == 4) {
        type = CV_8UC4;
    }
    return cv::Mat(image.height(), image.width(), type, image.data());
}
}  // namespace Impl
}  // namespace AutoMacro
