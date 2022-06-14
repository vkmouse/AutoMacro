#pragma once
#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/Image.h"

namespace AutoMacro {
class DLL_EXPORTS VideoCapture {
 public:
    virtual Image takeSnapshot() = 0;
};
}  // namespace AutoMacro
