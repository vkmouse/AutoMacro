#include "AutoMacro/Detection/DetectionResult.h"

#include "AutoMacro/Core/Types.h"

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

Rect DetectionResult::region() const {
    return Rect(x, y, width, height);
}

Point DetectionResult::center() const {
    return region().center();
}
}  // namespace Detection
}  // namespace AutoMacro
