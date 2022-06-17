#pragma once
#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/Keyboard.h"
#include "AutoMacro/Core/VideoCapture.h"
#include "AutoMacro/History/History/History.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS Keyboard* addKeyboardHistoryAgent(
    Keyboard* keyboard,
    History::Histories* histories);
DLL_EXPORTS VideoCapture* addVideoCaptureHistoryAgent(
    VideoCapture* videoCapture,
    History::Histories* histories);
}  // namespace Factory
}  // namespace AutoMacro
