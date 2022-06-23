#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Impl {
class DesktopCapture : public VideoCapture {
 public:
    DesktopCapture();

    virtual Image takeSnapshot();

 private:
    class Impl;
    std::unique_ptr<Impl> impl;
};
}  // namespace Impl
}  // namespace AutoMacro
