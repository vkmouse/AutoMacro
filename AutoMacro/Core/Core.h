#pragma once
#include <memory>

#include "AutoMacro/Core/Command/Command.h"
#include "AutoMacro/Core/Command/CommandParameter.h"
#include "AutoMacro/Core/Command/CommandsParameter.h"
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

DLL_EXPORTS std::shared_ptr<Command> createCommand();
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    CommandsParameter* p);
}  // namespace Factory
}  // namespace AutoMacro
