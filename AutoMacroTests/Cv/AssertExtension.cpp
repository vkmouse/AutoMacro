#include "AutoMacroTests/Cv/AssertExtension.h"
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
}  // namespace CppUnitTestFramework
}  // namespace VisualStudio
}  // namespace Microsoft
