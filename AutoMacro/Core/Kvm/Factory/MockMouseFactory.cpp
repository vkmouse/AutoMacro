#include "AutoMacro/Core/Kvm/Factory/MockMouseFactory.h"

#include <memory>

#include "AutoMacro/Core/Kvm/Kvm/MockMouse.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Mouse> createMockMouse() {
    return std::make_shared<Impl::MockMouse>();
}
}  // namespace Factory
}  // namespace AutoMacro
