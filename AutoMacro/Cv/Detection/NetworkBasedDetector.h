#pragma once
#include <string>

#include "opencv2/core.hpp"
#include "opencv2/dnn.hpp"
#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Cv/Detection/BaseDetector.h"

namespace AutoMacro {
namespace Impl {
class NetworkBasedDetector : public BaseDetector {
 public:
    NetworkBasedDetector(std::string modelName, std::string config,
                         int width, int height);

    void init() override;

 protected:
    DetectionResults detect(cv::Mat image) override;

 private:
    cv::Mat createBlob();
    cv::Mat inference(cv::InputArray blob);
    DetectionResults parseResult(cv::InputArray result);
    int roundToInt(float value);

    std::string modelName_;
    std::string config_;
    cv::Size size_;

    cv::Mat input;
    cv::dnn::Net net;
    double scalefactor = 1.0;
    cv::Scalar mean = cv::Scalar();
    bool swapRB = false;
};
}  // namespace Impl
}  // namespace AutoMacro
