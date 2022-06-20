#pragma once
#include <memory>

#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/Keyboard.h"

namespace AutoMacro {
namespace Impl {
class MockKeyboard : public Keyboard {
 public:
    virtual bool isKeyPressed(KeyCode key) const;
    virtual bool isKeyToggled(KeyCode key) const;

    virtual void pressKey(KeyCode key);
    virtual void releaseKey(KeyCode key);
    virtual void releaseAllKeys();
};
}  // namespace Impl
}  // namespace AutoMacro
