#pragma once
#include <memory>

#include "AutoMacro/Core/Kvm/VideoCapture.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<VideoCapture> createMockVideoCapture();
}  // namespace Factory
}  // namespace AutoMacro
