#pragma once
#include <memory>

#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/Keyboard.h"

namespace AutoMacro {
namespace Impl {
class DLL_EXPORTS MockKeyboard : public Keyboard {
 public:
    static bool isKeyPressed(KeyCode key);
    static bool isKeyToggled(KeyCode key);

    virtual void pressKey(KeyCode key);
    virtual void releaseKey(KeyCode key);
    virtual void releaseAllKeys();
};
}  // namespace Impl
}  // namespace AutoMacro
