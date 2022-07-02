#pragma once
#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Impl {
class MockVideoCapture : public VideoCapture {
 public:
    virtual Image takeSnapshot();
};
}  // namespace Impl
}  // namespace AutoMacro
