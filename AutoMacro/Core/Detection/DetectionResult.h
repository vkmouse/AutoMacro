#pragma once
#include <vector>

#include "AutoMacro/Core/Core/Types.h"

namespace AutoMacro {
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

typedef std::vector<DetectionResult> DetectionResults;
}  // namespace AutoMacro
