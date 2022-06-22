#pragma once
#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Impl {
class HIDKeyboard : public Keyboard {
 public:
    virtual bool isKeyPressed(KeyCode key) const;
    virtual bool isKeyToggled(KeyCode key) const;

    virtual void pressKey(KeyCode key);
    virtual void releaseKey(KeyCode key);
    virtual void releaseAllKeys();
};
}  // namespace Impl
}  // namespace AutoMacro
