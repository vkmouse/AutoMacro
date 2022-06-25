#pragma once
#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Detection {
class DLL_EXPORTS DetectionResult {
 public:
    DetectionResult();
    DetectionResult(
        int index,
        int x,
        int y,
        int width,
        int height,
        float confidence);
    DetectionResult(const DetectionResult& other) = default;

    DetectionResult& operator=(const DetectionResult& other) = default;
    bool operator==(const DetectionResult& other) const;

    Rect region() const;
    Point center() const;

    int index;
    int x;
    int y;
    int width;
    int height;
    float confidence;
};
}  // namespace Detection
}  // namespace AutoMacro
