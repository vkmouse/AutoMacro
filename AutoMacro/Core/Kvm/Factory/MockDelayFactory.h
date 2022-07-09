#pragma once
#include <memory>

#include "AutoMacro/Core/Kvm/Delay.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Delay> createMockDelay();
}  // namespace Factory
}  // namespace AutoMacro
