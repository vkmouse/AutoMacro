#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Impl {
class HIDMouse : public Mouse {
 public:
    HIDMouse();
    ~HIDMouse();

    virtual Point getCurrentPosition() const;
    virtual bool isMouseButtonDown(MouseButton button) const;

    virtual void mouseDown(MouseButton button);
    virtual void mouseUp(MouseButton button);
    virtual void mouseMove(int x, int y);
    virtual void releaseAllButtons();

 private:
    class Impl;
    std::unique_ptr<Impl> impl;
};
}  // namespace Impl
}  // namespace AutoMacro
