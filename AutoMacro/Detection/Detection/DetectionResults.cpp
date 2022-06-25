#include "AutoMacro/Detection/Detection/DetectionResults.h"

#include <functional>
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Detection/Detection/DetectionResult.h"

namespace AutoMacro {
namespace Detection {
namespace {
bool exists(const std::vector<DetectionResult>* results,
    std::function<bool(const DetectionResult&)> func) {
    auto iterator = std::find_if(results->begin(), results->end(), func);
    bool found = iterator != results->end();
    return found;
}

DetectionResults where(const std::vector<DetectionResult>* results,
    std::function<bool(const DetectionResult&)> func) {
    DetectionResults output;
    auto iterator = std::find_if(results->begin(), results->end(), func);
    while (iterator != results->end()) {
        output.push_back(*iterator);
        iterator = std::find_if(iterator + 1, results->end(), func);
    }
    return output;
}
}  // namespace

bool DetectionResults::exists(float threshold, int index) const {
    auto func = [&index, &threshold](const DetectionResult& item) {
        return item.index == index && item.confidence > threshold;
    };
    return AutoMacro::Detection::exists(this, func);
}

bool DetectionResults::exists(float threshold) const {
    auto func = [&threshold](const DetectionResult& item) {
        return item.confidence > threshold;
    };
    return AutoMacro::Detection::exists(this, func);
}

DetectionResults DetectionResults::where(float threshold, int index) const {
    auto func = [&index, &threshold](const DetectionResult& item) {
        return item.index == index && item.confidence > threshold;
    };
    return AutoMacro::Detection::where(this, func);
}

DetectionResults DetectionResults::where(float threshold) const {
    auto func = [&threshold](const DetectionResult& item) {
        return item.confidence > threshold;
    };
    return AutoMacro::Detection::where(this, func);
}

int DetectionResults::count(float threshold, int index) const {
    return static_cast<int>(where(threshold, index).size());
}

int DetectionResults::count(float threshold) const {
    return static_cast<int>(where(threshold).size());
}
}  // namespace Detection
}  // namespace AutoMacro
