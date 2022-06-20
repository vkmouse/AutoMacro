#include "AutoMacro/Detection/Detection/BaseDetector.h"

#include <opencv2/core.hpp>
#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Detection/Detection/DetectionResult.h"

namespace AutoMacro {
namespace Detection {
namespace Impl {
DetectionResults BaseDetector::detect(Image image) {
    cv::Mat mat = imageToMat(image);
    return detect(mat);
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
}  // namespace Detection
}  // namespace AutoMacro
