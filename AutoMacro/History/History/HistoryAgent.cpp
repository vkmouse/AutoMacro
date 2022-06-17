#include "AutoMacro/History/History/HistoryAgent.h"

#include "AutoMacro/Core/Keyboard.h"
#include "AutoMacro/Core/VideoCapture.h"
#include "AutoMacro/History/History/KeyboardHistoryAgent.h"
#include "AutoMacro/History/History/VideoCaptureHistoryAgent.h"

namespace AutoMacro {
namespace Factory {
Keyboard* addKeyboardHistoryAgent(
    Keyboard* keyboard,
    History::Histories* histories) {
    return new History::Impl::KeyboardHistoryAgent(keyboard, histories);
}

VideoCapture* addVideoCaptureHistoryAgent(
    VideoCapture* videoCapture,
    History::Histories* histories) {
    return new History::Impl::VideoCaptureHistoryAgent(videoCapture, histories);
}
}  // namespace Factory
}  // namespace AutoMacro
