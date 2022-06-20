#include "AutoMacro/Mouse/Mouse.h"

#include "AutoMacro/Mouse/Mouse/MockMouse.h"

namespace AutoMacro {
namespace Factory {
Mouse* createMockMouse() {
    return new Impl::MockMouse();
}
}  // namespace Factory
}  // namespace AutoMacro
