#pragma once
#include "AutoMacro/Core/Kvm/VideoCapture.h"

namespace AutoMacro {
namespace Impl {
class MockVideoCapture : public VideoCapture {
 public:
    virtual Image takeSnapshot() { return Image(0, 0, 0, nullptr); }
};
}  // namespace Impl
}  // namespace AutoMacro
