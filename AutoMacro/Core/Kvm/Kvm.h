#pragma once
#include <memory>

#include "AutoMacro/Core/Kvm/Delay.h"
#include "AutoMacro/Core/Kvm/Keyboard.h"
#include "AutoMacro/Core/Kvm/Mouse.h"
#include "AutoMacro/Core/Kvm/VideoCapture.h"

namespace AutoMacro {
struct Kvm {
    std::shared_ptr<Delay> delay;
    std::shared_ptr<Keyboard> keyboard;
    std::shared_ptr<Mouse> mouse;
    std::shared_ptr<VideoCapture> videoCapture;
};
}  // namespace AutoMacro
