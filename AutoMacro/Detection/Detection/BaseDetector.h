#pragma once
#include <opencv2/core.hpp>
#include "AutoMacro/Core/Image.h"
#include "AutoMacro/Detection/Detection/Detector.h"
#include "AutoMacro/Detection/Detection/DetectionResult.h"

namespace AutoMacro {
namespace Detection {
namespace Impl {
class BaseDetector : public Detector {
 public:
    DetectionResults detect(Image image) final;

 protected:
    using Detector::Detector;

    virtual DetectionResults detect(cv::Mat image) = 0;

 private:
     cv::Mat imageToMat(const Image& image);
};
}  // namespace Impl
}  // namespace Detection
}  // namespace AutoMacro
