#pragma once
#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/Keyboard.h"
#include "AutoMacro/Core/VideoCapture.h"
#include "AutoMacro/History/History/Histories.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS Keyboard* addHistoryAgent(
    Keyboard* keyboard,
    History::Histories* histories);
DLL_EXPORTS VideoCapture* addHistoryAgent(
    VideoCapture* videoCapture,
    History::Histories* histories);
}  // namespace Factory
}  // namespace AutoMacro
