#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/History/History/Histories.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Keyboard> addHistoryAgent(
    std::shared_ptr<Keyboard> keyboard,
    History::Histories* histories);
DLL_EXPORTS std::shared_ptr<VideoCapture> addHistoryAgent(
    std::shared_ptr<VideoCapture> videoCapture,
    History::Histories* histories);
}  // namespace Factory
}  // namespace AutoMacro
