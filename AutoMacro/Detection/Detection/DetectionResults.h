#pragma once
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Detection/Detection/DetectionResult.h"

namespace AutoMacro {
namespace Detection {
class DetectionResults : public std::vector<DetectionResult> {
 public:
    using vector::vector;

    DLL_EXPORTS bool exists(float threshold, int index) const;
    DLL_EXPORTS bool exists(float threshold) const;
    DLL_EXPORTS DetectionResults where(float threshold, int index) const;
    DLL_EXPORTS DetectionResults where(float threshold) const;
    DLL_EXPORTS int count(float threshold, int index) const;
    DLL_EXPORTS int count(float threshold) const;
};
}  // namespace Detection
}  // namespace AutoMacro
