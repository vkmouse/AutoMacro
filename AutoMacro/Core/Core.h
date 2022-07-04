#pragma once
#include <memory>

#include "AutoMacro/Core/Command.h"
#include "AutoMacro/Core/Core/Image.h"
#include "AutoMacro/Core/Core/Types.h"
#include "AutoMacro/Core/Detection/DetectionResult.h"
#include "AutoMacro/Core/Detection/Detector.h"
#include "AutoMacro/Core/ImageProcessor/ImageProcessor.h"
#include "AutoMacro/Core/Kvm/Delay.h"
#include "AutoMacro/Core/Kvm/Keyboard.h"
#include "AutoMacro/Core/Kvm/Kvm.h"
#include "AutoMacro/Core/Kvm/Mouse.h"
#include "AutoMacro/Core/Kvm/VideoCapture.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Delay> createMockDelay();
}  // namespace Factory
}  // namespace AutoMacro
