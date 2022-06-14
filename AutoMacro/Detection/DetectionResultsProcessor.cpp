#include "AutoMacro/Detection/DetectionResultsProcessor.h"

#include "AutoMacro/Detection/DetectionResult.h"

namespace AutoMacro {
namespace Detection {
bool itemExists(const DetectionResults& results, int index, float threshold) {
    auto func = [&index, &threshold](const DetectionResult& item) {
        return item.index == index && item.confidence > threshold;
    };
    auto iterator = std::find_if(results.begin(), results.end(), func);
    bool found = iterator != results.end();
    return found;
}
}  // namespace Detection
}  // namespace AutoMacro
