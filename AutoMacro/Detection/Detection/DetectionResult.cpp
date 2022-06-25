#include "AutoMacro/Detection/Detection/DetectionResult.h"

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Detection {
DetectionResult::DetectionResult() {
    index = 0;
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    confidence = 0.0f;
}

DetectionResult::DetectionResult(
    int index,
    int x,
    int y,
    int width,
    int height,
    float confidence) :
    index(index),
    x(x),
    y(y),
    width(width),
    height(height),
    confidence(confidence) {
}

bool DetectionResult::operator==(const DetectionResult& other) const {
    return index == other.index &&
        x == other.x &&
        y == other.y &&
        width == other.width &&
        height == other.height &&
        confidence == other.confidence;
}

Rect DetectionResult::region() const {
    return Rect(x, y, width, height);
}

Point DetectionResult::center() const {
    return region().center();
}

bool DetectionResults::exists(int index, float threshold) const {
    auto func = [&index, &threshold](const DetectionResult& item) {
        return item.index == index && item.confidence > threshold;
    };
    auto iterator = std::find_if(begin(), end(), func);
    bool found = iterator != end();
    return found;
}

bool DetectionResults::exists(float threshold) const {
    auto func = [&threshold](const DetectionResult& item) {
        return item.confidence > threshold;
    };
    auto iterator = std::find_if(begin(), end(), func);
    bool found = iterator != end();
    return found;
}
}  // namespace Detection
}  // namespace AutoMacro
