#pragma once
#include <vector>

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

class DetectionResults : public std::vector<DetectionResult> {
 public:
    DLL_EXPORTS bool exists(int index, float threshold) const;
    DLL_EXPORTS bool exists(float threshold) const;
};
}  // namespace Detection
}  // namespace AutoMacro
