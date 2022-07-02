#include "AutoMacro/Util/History/KeyboardHistoryAgent.h"

#include <memory>

#include "AutoMacro/Util/History/Histories.h"

namespace AutoMacro {
namespace Impl {
KeyboardHistoryAgent::KeyboardHistoryAgent(
    std::shared_ptr<Keyboard> keyboard, Histories* histories)
    : keyboard(keyboard), histories(histories) {
}

bool KeyboardHistoryAgent::isKeyPressed(KeyCode key) const {
    return keyboard->isKeyPressed(key);
}

bool KeyboardHistoryAgent::isKeyToggled(KeyCode key) const {
    return keyboard->isKeyToggled(key);
}

void KeyboardHistoryAgent::pressKey(KeyCode key) {
    keyboard->pressKey(key);
    histories->record("pressKey", key);
}

void KeyboardHistoryAgent::releaseKey(KeyCode key) {
    keyboard->releaseKey(key);
    histories->record("releaseKey", key);
}

void KeyboardHistoryAgent::releaseAllKeys() {
    keyboard->releaseAllKeys();
    histories->record("releaseAllKeys");
}
}  // namespace Impl
}  // namespace AutoMacro
