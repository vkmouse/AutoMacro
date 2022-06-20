#include "AutoMacro/History/History.h"

#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/History/History/KeyboardHistoryAgent.h"
#include "AutoMacro/History/History/VideoCaptureHistoryAgent.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Keyboard> addHistoryAgent(
    std::shared_ptr<Keyboard> keyboard,
    History::Histories* histories) {
    return std::make_shared<History::Impl::KeyboardHistoryAgent>(keyboard, histories);
}

VideoCapture* addHistoryAgent(
    VideoCapture* videoCapture,
    History::Histories* histories) {
    return new History::Impl::VideoCaptureHistoryAgent(videoCapture, histories);
}
}  // namespace Factory
}  // namespace AutoMacro
