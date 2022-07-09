#include "AutoMacro/Core/Kvm/Factory/MockDelayFactory.h"

#include <memory>

#include "AutoMacro/Core/Kvm/Kvm/MockDelay.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Delay> createMockDelay() {
    return std::make_shared<Impl::MockDelay>();
}
}  // namespace Factory
}  // namespace AutoMacro
