#pragma once
#include <memory>

#include "AutoMacro/Core/Core/Command.h"
#include "AutoMacro/Core/Core/CommandParameter.h"
#include "AutoMacro/Core/Core/DetectionResult.h"
#include "AutoMacro/Core/Core/Detector.h"
#include "AutoMacro/Core/Core/Image.h"
#include "AutoMacro/Core/Core/ImageProcessor.h"
#include "AutoMacro/Core/Core/Types.h"
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
