#include "AutoMacro/Util/Util.h"

#include <functional>
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Util/History/DelayHistoryAgent.h"
#include "AutoMacro/Util/History/KeyboardHistoryAgent.h"
#include "AutoMacro/Util/History/MouseHistoryAgent.h"
#include "AutoMacro/Util/History/VideoCaptureHistoryAgent.h"

namespace AutoMacro {
namespace Util {
namespace {
bool exists(const DetectionResults& results,
            std::function<bool(const DetectionResult&)> func) {
    auto iterator = std::find_if(results.begin(), results.end(), func);
    bool found = iterator != results.end();
    return found;
}

DetectionResults where(const DetectionResults& results,
                       std::function<bool(const DetectionResult&)> func) {
    DetectionResults output;
    auto iterator = std::find_if(results.begin(), results.end(), func);
    while (iterator != results.end()) {
        output.push_back(*iterator);
        iterator = std::find_if(iterator + 1, results.end(), func);
    }
    return output;
}
}  // namespace

bool exists(const DetectionResults& results, float threshold, int index) {
    auto func = [&index, &threshold](const DetectionResult& item) {
        return item.index == index && item.confidence > threshold;
    };
    return exists(results, func);
}

bool exists(const DetectionResults& results, float threshold) {
    auto func = [&threshold](const DetectionResult& item) {
        return item.confidence > threshold;
    };
    return exists(results, func);
}

DetectionResults where(const DetectionResults& results,
                       float threshold, int index) {
    auto func = [&index, &threshold](const DetectionResult& item) {
        return item.index == index && item.confidence > threshold;
    };
    return where(results, func);
}

DetectionResults where(const DetectionResults& results, float threshold) {
    auto func = [&threshold](const DetectionResult& item) {
        return item.confidence > threshold;
    };
    return where(results, func);
}

int count(const DetectionResults& results, float threshold, int index) {
    return static_cast<int>(where(results, threshold, index).size());
}

int count(const DetectionResults& results, float threshold) {
    return static_cast<int>(where(results, threshold).size());
}

std::shared_ptr<Keyboard> addHistoryAgent(
    std::shared_ptr<Keyboard> keyboard, Histories* histories) {
    return std::make_shared<Impl::KeyboardHistoryAgent>(
        keyboard, histories);
}

std::shared_ptr<Delay> addHistoryAgent(
    std::shared_ptr<Delay> delay, Histories* histories) {
    return std::make_shared<Impl::DelayHistoryAgent>(
        delay, histories);
}

std::shared_ptr<Mouse> addHistoryAgent(
    std::shared_ptr<Mouse> mouse, Histories* histories) {
    return std::make_shared<Impl::MouseHistoryAgent>(
        mouse, histories);
}

std::shared_ptr<VideoCapture> addHistoryAgent(
    std::shared_ptr<VideoCapture> videoCapture, Histories* histories) {
    return std::make_shared<Impl::VideoCaptureHistoryAgent>(
        videoCapture, histories);
}

int calcDuration(History start, History last) {
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;
    auto duration = duration_cast<milliseconds>(last.time() - start.time());
    return static_cast<int>(duration.count());
}
}  // namespace Util
}  // namespace AutoMacro
