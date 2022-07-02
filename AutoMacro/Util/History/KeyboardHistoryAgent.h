#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Util/History/Histories.h"

namespace AutoMacro {
namespace Impl {
class KeyboardHistoryAgent : public Keyboard {
 public:
    KeyboardHistoryAgent(std::shared_ptr<Keyboard> keyboard,
                         Histories* histories);

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
}  // namespace AutoMacro
