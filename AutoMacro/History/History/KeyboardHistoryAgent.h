#pragma once
#include <memory>
#include <string>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/History/History/Histories.h"

namespace AutoMacro {
namespace History {
namespace Impl {
class KeyboardHistoryAgent : public Keyboard {
 public:
    static std::string keyToString(KeyCode key);

    KeyboardHistoryAgent(std::shared_ptr<Keyboard> keyboard, Histories* histories);

    virtual bool isKeyPressed(KeyCode key) const;
    virtual bool isKeyToggled(KeyCode key) const;

    virtual void pressKey(KeyCode key);
    virtual void releaseKey(KeyCode key);
    virtual void releaseAllKeys();

 private:
    std::shared_ptr<Keyboard> keyboard;
    Histories* histories;
};
}  // namespace Impl
}  // namespace History
}  // namespace AutoMacro
