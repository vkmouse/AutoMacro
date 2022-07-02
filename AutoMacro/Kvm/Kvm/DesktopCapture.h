#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Impl {
class DesktopCapture : public BaseVideoCapture {
 public:
    DesktopCapture();

 protected:
    virtual Image takeSnapshotWithoutPostprocessing();

 private:
    class Impl;
    std::unique_ptr<Impl> impl;
};
}  // namespace Impl
}  // namespace AutoMacro
