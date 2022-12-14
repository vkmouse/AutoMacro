#pragma once
#include <memory>
#include <vector>

#include "opencv2/core.hpp"
#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Impl {
class BaseDetector : public Detector {
 public:
    DetectionResults detect(Image image) final;

 protected:
    using Detector::Detector;

    void addPreprocessor(std::shared_ptr<ImageProcessor> processor) final;
    void removeLastPreprocessor() final;

    virtual DetectionResults detect(cv::Mat image) = 0;

 private:
    cv::Mat imageToMat(const Image& image);

    std::vector<std::shared_ptr<ImageProcessor>> preprocessors;
};
}  // namespace Impl
}  // namespace AutoMacro
