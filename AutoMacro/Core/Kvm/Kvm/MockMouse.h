#pragma once
#include "AutoMacro/Core/Kvm/Mouse.h"

namespace AutoMacro {
namespace Impl {
class MockMouse : public Mouse {
 public:
    virtual Point getCurrentPosition() const;
    virtual bool isMouseButtonDown(MouseButton button) const;

    virtual void mouseDown(MouseButton button);
    virtual void mouseUp(MouseButton button);
    virtual void mouseMove(int x, int y);
    virtual void releaseAllButtons();
};
}  // namespace Impl
}  // namespace AutoMacro
