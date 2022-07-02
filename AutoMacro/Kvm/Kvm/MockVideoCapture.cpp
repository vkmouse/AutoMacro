#include "AutoMacro/Kvm/Kvm/MockVideoCapture.h"

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Impl {
Image MockVideoCapture::takeSnapshot() {
    return Image(0, 0, 0, nullptr);
}
}  // namespace Impl
}  // namespace AutoMacro
