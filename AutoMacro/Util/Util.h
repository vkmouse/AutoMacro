#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Util/History/Histories.h"

namespace AutoMacro {
namespace Util {
DLL_EXPORTS bool exists(const DetectionResults& results,
                        float threshold, int index);
DLL_EXPORTS bool exists(const DetectionResults& results,
                        float threshold);
DLL_EXPORTS DetectionResults where(const DetectionResults& results,
                                   float threshold, int index);
DLL_EXPORTS DetectionResults where(const DetectionResults& results,
                                   float threshold);
DLL_EXPORTS int count(const DetectionResults& results,
                      float threshold, int index);
DLL_EXPORTS int count(const DetectionResults& results,
                      float threshold);

DLL_EXPORTS std::shared_ptr<Delay> addHistoryAgent(
    std::shared_ptr<Delay> delay, Histories* histories);
DLL_EXPORTS std::shared_ptr<Keyboard> addHistoryAgent(
    std::shared_ptr<Keyboard> keyboard, Histories* histories);
DLL_EXPORTS std::shared_ptr<Mouse> addHistoryAgent(
    std::shared_ptr<Mouse> mouse, Histories* histories);
DLL_EXPORTS std::shared_ptr<VideoCapture> addHistoryAgent(
    std::shared_ptr<VideoCapture> videoCapture, Histories* histories);
DLL_EXPORTS int calcDuration(History start, History last);
}  // namespace Util
}  // namespace AutoMacro
