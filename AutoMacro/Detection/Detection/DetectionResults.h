#pragma once
#include <functional>
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Detection/Detection/DetectionResult.h"

namespace AutoMacro {
namespace Detection {
class DetectionResults : public std::vector<DetectionResult> {
 public:
    DLL_EXPORTS bool exists(float threshold, int index) const;
    DLL_EXPORTS bool exists(float threshold) const;
    DLL_EXPORTS DetectionResults where(float threshold) const;
    DLL_EXPORTS int count(float threshold) const;

 private:
    bool exists(std::function<bool(const DetectionResult&)> func) const;
    DetectionResults where(
        std::function<bool(const DetectionResult&)> func) const;
};
}  // namespace Detection
}  // namespace AutoMacro
