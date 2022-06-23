#include "AutoMacro/History/History/KeyboardHistoryAgent.h"

#include <memory>
#include <string>

#include "AutoMacro/History/History/Histories.h"

namespace AutoMacro {
namespace History {
namespace Impl {
std::string KeyboardHistoryAgent::keyToString(KeyCode key) {
    switch (key) {
    case KeyCode::KEY_NONE: return "KEY_NONE";
    case KeyCode::KEY_A: return "KEY_A";
    case KeyCode::KEY_B: return "KEY_B";
    case KeyCode::KEY_C: return "KEY_C";
    case KeyCode::KEY_D: return "KEY_D";
    case KeyCode::KEY_E: return "KEY_E";
    case KeyCode::KEY_F: return "KEY_F";
    case KeyCode::KEY_G: return "KEY_G";
    case KeyCode::KEY_H: return "KEY_H";
    case KeyCode::KEY_I: return "KEY_I";
    case KeyCode::KEY_J: return "KEY_J";
    case KeyCode::KEY_K: return "KEY_K";
    case KeyCode::KEY_L: return "KEY_L";
    case KeyCode::KEY_M: return "KEY_M";
    case KeyCode::KEY_N: return "KEY_N";
    case KeyCode::KEY_O: return "KEY_O";
    case KeyCode::KEY_P: return "KEY_P";
    case KeyCode::KEY_Q: return "KEY_Q";
    case KeyCode::KEY_R: return "KEY_R";
    case KeyCode::KEY_S: return "KEY_S";
    case KeyCode::KEY_T: return "KEY_T";
    case KeyCode::KEY_U: return "KEY_U";
    case KeyCode::KEY_V: return "KEY_V";
    case KeyCode::KEY_W: return "KEY_W";
    case KeyCode::KEY_X: return "KEY_X";
    case KeyCode::KEY_Y: return "KEY_Y";
    case KeyCode::KEY_Z: return "KEY_Z";
    case KeyCode::KEY_1: return "KEY_1";
    case KeyCode::KEY_2: return "KEY_2";
    case KeyCode::KEY_3: return "KEY_3";
    case KeyCode::KEY_4: return "KEY_4";
    case KeyCode::KEY_5: return "KEY_5";
    case KeyCode::KEY_6: return "KEY_6";
    case KeyCode::KEY_7: return "KEY_7";
    case KeyCode::KEY_8: return "KEY_8";
    case KeyCode::KEY_9: return "KEY_9";
    case KeyCode::KEY_0: return "KEY_0";
    case KeyCode::KEY_ENTER: return "KEY_ENTER";
    case KeyCode::KEY_ESC: return "KEY_ESC";
    case KeyCode::KEY_BACKSPACE: return "KEY_BACKSPACE";
    case KeyCode::KEY_TAB: return "KEY_TAB";
    case KeyCode::KEY_SPACE: return "KEY_SPACE";
    case KeyCode::KEY_MINUS: return "KEY_MINUS";
    case KeyCode::KEY_EQUAL: return "KEY_EQUAL";
    case KeyCode::KEY_LEFTBRACE: return "KEY_LEFTBRACE";
    case KeyCode::KEY_RIGHTBRACE: return "KEY_RIGHTBRACE";
    case KeyCode::KEY_BACKSLASH: return "KEY_BACKSLASH";
    case KeyCode::KEY_HASHTILDE: return "KEY_HASHTILDE";
    case KeyCode::KEY_SEMICOLON: return "KEY_SEMICOLON";
    case KeyCode::KEY_APOSTROPHE: return "KEY_APOSTROPHE";
    case KeyCode::KEY_GRAVE: return "KEY_GRAVE";
    case KeyCode::KEY_COMMA: return "KEY_COMMA";
    case KeyCode::KEY_DOT: return "KEY_DOT";
    case KeyCode::KEY_SLASH: return "KEY_SLASH";
    case KeyCode::KEY_CAPSLOCK: return "KEY_CAPSLOCK";
    case KeyCode::KEY_F1: return "KEY_F1";
    case KeyCode::KEY_F2: return "KEY_F2";
    case KeyCode::KEY_F3: return "KEY_F3";
    case KeyCode::KEY_F4: return "KEY_F4";
    case KeyCode::KEY_F5: return "KEY_F5";
    case KeyCode::KEY_F6: return "KEY_F6";
    case KeyCode::KEY_F7: return "KEY_F7";
    case KeyCode::KEY_F8: return "KEY_F8";
    case KeyCode::KEY_F9: return "KEY_F9";
    case KeyCode::KEY_F10: return "KEY_F10";
    case KeyCode::KEY_F11: return "KEY_F11";
    case KeyCode::KEY_F12: return "KEY_F12";
    case KeyCode::KEY_SYSRQ: return "KEY_SYSRQ";
    case KeyCode::KEY_SCROLLLOCK: return "KEY_SCROLLLOCK";
    case KeyCode::KEY_PAUSE: return "KEY_PAUSE";
    case KeyCode::KEY_INSERT: return "KEY_INSERT";
    case KeyCode::KEY_HOME: return "KEY_HOME";
    case KeyCode::KEY_PAGEUP: return "KEY_PAGEUP";
    case KeyCode::KEY_DELETE: return "KEY_DELETE";
    case KeyCode::KEY_END: return "KEY_END";
    case KeyCode::KEY_PAGEDOWN: return "KEY_PAGEDOWN";
    case KeyCode::KEY_RIGHT: return "KEY_RIGHT";
    case KeyCode::KEY_LEFT: return "KEY_LEFT";
    case KeyCode::KEY_DOWN: return "KEY_DOWN";
    case KeyCode::KEY_UP: return "KEY_UP";
    case KeyCode::KEY_NUMLOCK: return "KEY_NUMLOCK";
    case KeyCode::KEY_KPSLASH: return "KEY_KPSLASH";
    case KeyCode::KEY_KPASTERISK: return "KEY_KPASTERISK";
    case KeyCode::KEY_KPMINUS: return "KEY_KPMINUS";
    case KeyCode::KEY_KPPLUS: return "KEY_KPPLUS";
    case KeyCode::KEY_KPENTER: return "KEY_KPENTER";
    case KeyCode::KEY_KP1: return "KEY_KP1";
    case KeyCode::KEY_KP2: return "KEY_KP2";
    case KeyCode::KEY_KP3: return "KEY_KP3";
    case KeyCode::KEY_KP4: return "KEY_KP4";
    case KeyCode::KEY_KP5: return "KEY_KP5";
    case KeyCode::KEY_KP6: return "KEY_KP6";
    case KeyCode::KEY_KP7: return "KEY_KP7";
    case KeyCode::KEY_KP8: return "KEY_KP8";
    case KeyCode::KEY_KP9: return "KEY_KP9";
    case KeyCode::KEY_KP0: return "KEY_KP0";
    case KeyCode::KEY_KPDOT: return "KEY_KPDOT";
    case KeyCode::KEY_102ND: return "KEY_102ND";
    case KeyCode::KEY_COMPOSE: return "KEY_COMPOSE";
    case KeyCode::KEY_LCTRL: return "KEY_LEFTCTRL";
    case KeyCode::KEY_LSHIFT: return "KEY_LEFTSHIFT";
    case KeyCode::KEY_LALT: return "KEY_LEFTALT";
    case KeyCode::KEY_LMETA: return "KEY_LEFTMETA";
    case KeyCode::KEY_RCTRL: return "KEY_RIGHTCTRL";
    case KeyCode::KEY_RSHIFT: return "KEY_RIGHTSHIFT";
    case KeyCode::KEY_RALT: return "KEY_RIGHTALT";
    case KeyCode::KEY_RMETA: return "KEY_RIGHTMETA";
    default: return "";
    }
}

KeyboardHistoryAgent::KeyboardHistoryAgent(
    std::shared_ptr<Keyboard> keyboard,
    Histories* histories) :
    keyboard(keyboard),
    histories(histories) {
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
}  // namespace History
}  // namespace AutoMacro
