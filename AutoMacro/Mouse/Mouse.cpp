#include "AutoMacro/Mouse/Mouse.h"

#include <memory>

#include "AutoMacro/Mouse/Mouse/MockMouse.h"

namespace AutoMacro {
namespace Factory {
std::shared_ptr<Mouse> createMockMouse() {
    return std::make_shared<Impl::MockMouse>();
}
}  // namespace Factory
}  // namespace AutoMacro
