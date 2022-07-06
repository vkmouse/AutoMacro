#include "AutoMacro/Cv/Detection/NetworkBasedDetector.h"

#include <cmath>
#include <string>

#include "opencv2/dnn.hpp"

namespace AutoMacro {
namespace Impl {
NetworkBasedDetector::NetworkBasedDetector(
    std::string modelName, std::string config, int width, int height)
    : modelName_(modelName), config_(config), size_({ width, height }) {
}

void NetworkBasedDetector::init() {
    net = cv::dnn::readNet(modelName_, config_);
    net.setPreferableBackend(cv::dnn::DNN_BACKEND_INFERENCE_ENGINE);
    net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);
}

DetectionResults NetworkBasedDetector::detect(cv::Mat image) {
    input = image;
    cv::Mat blob = createBlob();
    cv::Mat result = inference(blob);
    return parseResult(result);
}

cv::Mat NetworkBasedDetector::createBlob() {
    return cv::dnn::blobFromImage(input, scalefactor, size_, mean, swapRB);
}

cv::Mat NetworkBasedDetector::inference(cv::InputArray blob) {
    net.setInput(blob);
    return net.forward();
}

DetectionResults NetworkBasedDetector::parseResult(cv::InputArray result) {
    cv::Mat mat = result.getMat();
    cv::MatSize shape = mat.size;
    int numBBoxes = shape[0] * shape[1] * shape[2] * shape[3];
    float* data = reinterpret_cast<float*>(mat.data);

    DetectionResults output;

    for (size_t i = 0; i < numBBoxes; i += 7) {
        int index = static_cast<int>(data[i + 1]);
        float confidence = data[i + 2];
        int x = roundToInt(data[i + 3] * input.cols);
        int y = roundToInt(data[i + 4] * input.rows);
        int width = roundToInt((data[i + 5] - data[i + 3]) * input.cols);
        int height = roundToInt((data[i + 6] - data[i + 4]) * input.rows);

        DetectionResult res(index, x, y, width, height, confidence);
        output.push_back(res);
    }

    return output;
}

int NetworkBasedDetector::roundToInt(float value) {
    return static_cast<int>(std::roundf(value));
}
}  // namespace Impl
}  // namespace AutoMacro
