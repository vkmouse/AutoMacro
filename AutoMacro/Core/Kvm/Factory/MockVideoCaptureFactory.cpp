#include "AutoMacro/Core/Kvm/Factory/MockVideoCaptureFactory.h"

#include <memory>

#include "AutoMacro/Core/Kvm/Kvm/MockVideoCapture.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<VideoCapture> createMockVideoCapture() {
    return std::make_shared<Impl::MockVideoCapture>();
}
}  // namespace Factory
}  // namespace AutoMacro
