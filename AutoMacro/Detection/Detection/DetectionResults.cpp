#include "AutoMacro/Detection/Detection/DetectionResults.h"

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Detection/Detection/DetectionResult.h"

namespace AutoMacro {
namespace Detection {
bool DetectionResults::exists(float threshold, int index) const {
    auto func = [&index, &threshold](const DetectionResult& item) {
        return item.index == index && item.confidence > threshold;
    };
    return exists(func);
}

bool DetectionResults::exists(float threshold) const {
    auto func = [&threshold](const DetectionResult& item) {
        return item.confidence > threshold;
    };
    return exists(func);
}

DetectionResults DetectionResults::where(float threshold) const {
    auto func = [&threshold](const DetectionResult& item) {
        return item.confidence > threshold;
    };
    return where(func);
}

int DetectionResults::count(float threshold) const {
    return static_cast<int>(where(threshold).size());
}

bool DetectionResults::exists(
    std::function<bool(const DetectionResult&)> func) const {
    auto iterator = std::find_if(begin(), end(), func);
    bool found = iterator != end();
    return found;
}

DetectionResults DetectionResults::where(
    std::function<bool(const DetectionResult&)> func) const {
    DetectionResults results;
    auto iterator = std::find_if(begin(), end(), func);
    while (iterator != end()) {
        results.push_back(*iterator);
        iterator = std::find_if(iterator + 1, end(), func);
    }
    return results;
}
}  // namespace Detection
}  // namespace AutoMacro
