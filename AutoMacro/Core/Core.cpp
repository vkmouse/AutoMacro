#include "AutoMacro/Core/Core.h"

#include <memory>

#include "AutoMacro/Core/Kvm/MockDelay.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Delay> createMockDelay() {
    return std::make_shared<Impl::MockDelay>();
}
}  // namespace Factory
}  // namespace AutoMacro
