#pragma once
#include <memory>

#include "AutoMacro/Core/Command/Command.h"
#include "AutoMacro/Core/Command/CommandParameter.h"
#include "AutoMacro/Core/Command/CommandsParameter.h"
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

DLL_EXPORTS std::shared_ptr<Command> createCommands(
    CommandsParameter* p);
}  // namespace Factory
}  // namespace AutoMacro
