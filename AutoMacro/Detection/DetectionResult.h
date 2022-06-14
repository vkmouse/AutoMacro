#pragma once
#include <vector>

#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/Types.h"

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
}  // namespace Detection
}  // namespace AutoMacro
