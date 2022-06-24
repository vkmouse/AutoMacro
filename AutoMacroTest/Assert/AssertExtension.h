#pragma once
#include "CppUnitTest.h"
#include <AutoMacro/Core/Core.h>
#include <AutoMacro/Detection/Detection.h>

namespace Microsoft {
namespace VisualStudio {
namespace CppUnitTestFramework {
std::wstring ToString(AutoMacro::Image value);
std::wstring ToString(AutoMacro::Detection::DetectionResult value);
}  // namespace CppUnitTestFramework
}  // namespace VisualStudio
}  // namespace Microsoft
