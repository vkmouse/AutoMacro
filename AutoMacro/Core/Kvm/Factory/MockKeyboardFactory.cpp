#include "AutoMacro/Core/Kvm/Factory/MockKeyboardFactory.h"

#include <memory>

#include "AutoMacro/Core/Kvm/Kvm/MockKeyboard.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Keyboard> createMockKeyboard() {
    return std::make_shared<Impl::MockKeyboard>();
}
}  // namespace Factory
}  // namespace AutoMacro
