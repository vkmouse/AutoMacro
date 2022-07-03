#pragma once
#include <memory>

#include "AutoMacro/Core/Core/Delay.h"
#include "AutoMacro/Core/Core/Keyboard.h"
#include "AutoMacro/Core/Core/Mouse.h"
#include "AutoMacro/Core/Core/VideoCapture.h"

namespace AutoMacro {
struct Kvm {
    std::shared_ptr<Delay> delay;
    std::shared_ptr<Keyboard> keyboard;
    std::shared_ptr<Mouse> mouse;
    std::shared_ptr<VideoCapture> videoCapture;
};
}  // namespace AutoMacro
