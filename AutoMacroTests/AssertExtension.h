#pragma once
#include "AutoMacro/Core/Core.h"
#include "CppUnitTest.h"

namespace Microsoft {
namespace VisualStudio {
namespace CppUnitTestFramework {
std::wstring ToString(AutoMacro::Image value);
std::wstring ToString(AutoMacro::Rect value);
std::wstring ToString(AutoMacro::DetectionResult value);
}  // namespace CppUnitTestFramework
}  // namespace VisualStudio
}  // namespace Microsoft
