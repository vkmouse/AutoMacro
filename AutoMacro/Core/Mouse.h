#pragma once
#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/Types.h"

namespace AutoMacro {
enum class MouseButton : unsigned char {
    BUTTON_NONE = 0x00,
    BUTTON_LEFT = 0x01,
    BUTTON_RIGHT = 0x02,
    BUTTON_MIDDLE = 0x04
};

class DLL_EXPORTS Mouse {
 public:
    virtual Point getCurrentPosition() const = 0;
    virtual bool isMouseButtonDown(MouseButton button) const = 0;
    
    virtual void mouseDown(MouseButton button) = 0;
    virtual void mouseUp(MouseButton button) = 0;
    virtual void mouseMove(int x, int y) = 0;
    virtual void releaseAllButtons() = 0;
};
}  // namespace AutoMacro
