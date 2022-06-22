#pragma once
#include <memory>

#include <AutoMacro/Core/Core.h>

namespace AutoMacro {
class KeyboardTest {
 protected:
    virtual std::shared_ptr<Keyboard> createKeyboard() = 0;

    void TestKeyboardPressAndReleaseKey();
    void TestKeyboardReleaseAllKeys();
    void TestKeyboardToggleKey();
};
}  // namespace AutoMacro
