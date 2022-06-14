#pragma once
#include <string>

#include "AutoMacro/Core/pch.h"
#include "AutoMacro/Core/Keyboard.h"
#include "AutoMacro/History/History.h"

namespace AutoMacro {
namespace History {
namespace Impl {
class DLL_EXPORTS KeyboardHistoryAgent : public Keyboard {
 public:
    static std::string keyToString(KeyCode key);

    KeyboardHistoryAgent(Keyboard* keyboard, Histories* histories);

    virtual void pressKey(KeyCode key);
    virtual void releaseKey(KeyCode key);
    virtual void releaseAllKeys();

 private:
    Keyboard* keyboard;
    Histories* histories;
};
}  // namespace Impl
}  // namespace History
}  // namespace AutoMacro
