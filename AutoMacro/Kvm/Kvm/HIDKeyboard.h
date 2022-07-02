#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Impl {
class HIDKeyboard : public Keyboard {
 public:
    HIDKeyboard();
    ~HIDKeyboard();

    virtual bool isKeyPressed(KeyCode key) const;
    virtual bool isKeyToggled(KeyCode key) const;

    virtual void pressKey(KeyCode key);
    virtual void releaseKey(KeyCode key);
    virtual void releaseAllKeys();

 private:
    class Impl;
    std::unique_ptr<Impl> impl;
};
}  // namespace Impl
}  // namespace AutoMacro
