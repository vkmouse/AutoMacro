#include "AutoMacroTests/AssertExtension.h"
#include "AutoMacro/Core/Core.h"
#include "CppUnitTest.h"

namespace Microsoft {
namespace VisualStudio {
namespace CppUnitTestFramework {
std::wstring ToString(AutoMacro::Image value) {
    std::wstring str = L"";
    int size = value.width() * value.height() * value.channel();
    for (int i = 0; i < size; i++) {
        str += std::to_wstring(value.data()[i]);
    }
    return str;
}

std::wstring ToString(AutoMacro::Rect value) {
    std::wstring str = L"";
    str += std::to_wstring(value.x) + L",";
    str += std::to_wstring(value.y) + L",";
    str += std::to_wstring(value.width) + L",";
    str += std::to_wstring(value.height);
    return str;
}

std::wstring ToString(AutoMacro::DetectionResult value) {
    std::wstring str = std::to_wstring(value.index);
    str += std::to_wstring(value.x);
    str += std::to_wstring(value.y);
    str += std::to_wstring(value.width);
    str += std::to_wstring(value.height);
    str += std::to_wstring(value.confidence);
    return str;
}
}  // namespace CppUnitTestFramework
}  // namespace VisualStudio
}  // namespace Microsoft
