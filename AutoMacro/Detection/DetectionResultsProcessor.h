#pragma once
#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Detection/DetectionResult.h"

namespace AutoMacro {
namespace Detection {
DLL_EXPORTS bool itemExists(
    const DetectionResults& results,
    int index,
    float threshold);
}  // namespace Detection
}  // namespace AutoMacro
