#include "AutoMacro/KbdMou/KbdMou/HIDKeyboard.h"

#include <Windows.h>
#include <stdexcept>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/KbdMou/KbdMou/KbdMouDevice.h"

namespace AutoMacro {
namespace Impl {
namespace {
bool isModifier(KeyCode key) {
    switch (key) {
    case KeyCode::KEY_LCTRL:
    case KeyCode::KEY_LSHIFT:
    case KeyCode::KEY_LALT:
    case KeyCode::KEY_LMETA:
    case KeyCode::KEY_RCTRL:
    case KeyCode::KEY_RSHIFT:
    case KeyCode::KEY_RALT:
    case KeyCode::KEY_RMETA:
        return true;
    default:
        return false;
    }
}

unsigned char getModifier(KeyCode key) {
    switch (key) {
    case KeyCode::KEY_LCTRL: return 0x01;
    case KeyCode::KEY_LSHIFT: return 0x02;
    case KeyCode::KEY_LALT: return 0x04;
    case KeyCode::KEY_LMETA: return 0x08;
    case KeyCode::KEY_RCTRL: return 0x10;
    case KeyCode::KEY_RSHIFT: return 0x20;
    case KeyCode::KEY_RALT: return 0x40;
    case KeyCode::KEY_RMETA: return 0x80;
    default: return 0x00;
    }
}

int getVirtualKey(KeyCode key) {
    switch (key) {
    case KeyCode::KEY_NONE: return 0;

    case KeyCode::KEY_A: return 'A';
    case KeyCode::KEY_B: return 'B';
    case KeyCode::KEY_C: return 'C';
    case KeyCode::KEY_D: return 'D';
    case KeyCode::KEY_E: return 'E';
    case KeyCode::KEY_F: return 'F';
    case KeyCode::KEY_G: return 'G';
    case KeyCode::KEY_H: return 'H';
    case KeyCode::KEY_I: return 'I';
    case KeyCode::KEY_J: return 'J';
    case KeyCode::KEY_K: return 'K';
    case KeyCode::KEY_L: return 'L';
    case KeyCode::KEY_M: return 'M';
    case KeyCode::KEY_N: return 'N';
    case KeyCode::KEY_O: return 'O';
    case KeyCode::KEY_P: return 'P';
    case KeyCode::KEY_Q: return 'Q';
    case KeyCode::KEY_R: return 'R';
    case KeyCode::KEY_S: return 'S';
    case KeyCode::KEY_T: return 'T';
    case KeyCode::KEY_U: return 'U';
    case KeyCode::KEY_V: return 'V';
    case KeyCode::KEY_W: return 'W';
    case KeyCode::KEY_X: return 'X';
    case KeyCode::KEY_Y: return 'Y';
    case KeyCode::KEY_Z: return 'Z';

    case KeyCode::KEY_1: return '1';
    case KeyCode::KEY_2: return '2';
    case KeyCode::KEY_3: return '3';
    case KeyCode::KEY_4: return '4';
    case KeyCode::KEY_5: return '5';
    case KeyCode::KEY_6: return '6';
    case KeyCode::KEY_7: return '7';
    case KeyCode::KEY_8: return '8';
    case KeyCode::KEY_9: return '9';
    case KeyCode::KEY_0: return '0';

    case KeyCode::KEY_ENTER: return VK_RETURN;
    case KeyCode::KEY_ESC: return VK_ESCAPE;
    case KeyCode::KEY_BACKSPACE: return VK_BACK;
    case KeyCode::KEY_TAB: return VK_TAB;
    case KeyCode::KEY_SPACE: return VK_SPACE;
    case KeyCode::KEY_MINUS: return VK_OEM_MINUS;
    case KeyCode::KEY_EQUAL: return VK_OEM_PLUS;
    case KeyCode::KEY_LEFTBRACE: return VK_OEM_4;
    case KeyCode::KEY_RIGHTBRACE: return VK_OEM_6;
    case KeyCode::KEY_BACKSLASH: return VK_OEM_5;
    case KeyCode::KEY_HASHTILDE: return VK_OEM_5;
    case KeyCode::KEY_SEMICOLON: return VK_OEM_1;
    case KeyCode::KEY_APOSTROPHE: return VK_OEM_7;
    case KeyCode::KEY_GRAVE: return VK_OEM_3;
    case KeyCode::KEY_COMMA: return VK_OEM_COMMA;
    case KeyCode::KEY_DOT: return VK_OEM_PERIOD;
    case KeyCode::KEY_SLASH: return VK_OEM_2;
    case KeyCode::KEY_CAPSLOCK: return VK_CAPITAL;

    case KeyCode::KEY_F1: return VK_F1;
    case KeyCode::KEY_F2: return VK_F2;
    case KeyCode::KEY_F3: return VK_F3;
    case KeyCode::KEY_F4: return VK_F4;
    case KeyCode::KEY_F5: return VK_F5;
    case KeyCode::KEY_F6: return VK_F6;
    case KeyCode::KEY_F7: return VK_F7;
    case KeyCode::KEY_F8: return VK_F8;
    case KeyCode::KEY_F9: return VK_F9;
    case KeyCode::KEY_F10: return VK_F10;
    case KeyCode::KEY_F11: return VK_F11;
    case KeyCode::KEY_F12: return VK_F12;

    case KeyCode::KEY_SYSRQ: return VK_SNAPSHOT;
    case KeyCode::KEY_SCROLLLOCK: return VK_SCROLL;
    case KeyCode::KEY_PAUSE: return VK_PAUSE;
    case KeyCode::KEY_INSERT: return VK_INSERT;
    case KeyCode::KEY_HOME: return VK_HOME;
    case KeyCode::KEY_PAGEUP: return VK_PRIOR;
    case KeyCode::KEY_DELETE: return VK_DELETE;
    case KeyCode::KEY_END: return VK_END;
    case KeyCode::KEY_PAGEDOWN: return VK_NEXT;
    case KeyCode::KEY_RIGHT: return VK_RIGHT;
    case KeyCode::KEY_LEFT: return VK_LEFT;
    case KeyCode::KEY_DOWN: return VK_DOWN;
    case KeyCode::KEY_UP: return VK_UP;

    case KeyCode::KEY_NUMLOCK: return VK_NUMLOCK;
    case KeyCode::KEY_KPSLASH: return VK_DIVIDE;
    case KeyCode::KEY_KPASTERISK: return VK_MULTIPLY;
    case KeyCode::KEY_KPMINUS: return VK_SUBTRACT;
    case KeyCode::KEY_KPPLUS: return VK_ADD;
    case KeyCode::KEY_KPENTER: return VK_RETURN;
    case KeyCode::KEY_KP1: return VK_NUMPAD1;
    case KeyCode::KEY_KP2: return VK_NUMPAD2;
    case KeyCode::KEY_KP3: return VK_NUMPAD3;
    case KeyCode::KEY_KP4: return VK_NUMPAD4;
    case KeyCode::KEY_KP5: return VK_NUMPAD5;
    case KeyCode::KEY_KP6: return VK_NUMPAD6;
    case KeyCode::KEY_KP7: return VK_NUMPAD7;
    case KeyCode::KEY_KP8: return VK_NUMPAD8;
    case KeyCode::KEY_KP9: return VK_NUMPAD9;
    case KeyCode::KEY_KP0: return VK_NUMPAD0;
    case KeyCode::KEY_KPDOT: return VK_DECIMAL;

    case KeyCode::KEY_102ND: return VK_OEM_102;
    case KeyCode::KEY_COMPOSE: return VK_APPS;

    case KeyCode::KEY_LCTRL: return VK_LCONTROL;
    case KeyCode::KEY_LSHIFT: return VK_LSHIFT;
    case KeyCode::KEY_LALT: return VK_LMENU;
    case KeyCode::KEY_LMETA: return VK_LWIN;
    case KeyCode::KEY_RCTRL: return VK_RCONTROL;
    case KeyCode::KEY_RSHIFT: return VK_RSHIFT;
    case KeyCode::KEY_RALT: return VK_RMENU;
    case KeyCode::KEY_RMETA: return VK_RWIN;
    default: return 0;
    }
}
}  // namespace

class HIDKeyboard::Impl : public KbdMouDevice {
 public:
    explicit Impl(const HIDKeyboard& keyboard) :
        KbdMouDevice(L"\\\\?\\HID#VARIABLE_6&Col04#1"),
        keyboard(keyboard) {
    }

    void pressModifier(KeyCode key) {
        modifiers = modifiers | getModifier(key);
        sendKeyboardReport();
    }

    void pressKey(KeyCode key) {
        if (canPressKey(key)) {
            replaceFirstKey(KeyCode::KEY_NONE, key);
            sendKeyboardReport();
        }
    }

    void releaseModifier(KeyCode key) {
        modifiers = modifiers & ~getModifier(key);
        sendKeyboardReport();
    }

    void releaseKey(KeyCode key) {
        if (canReleaseKey(key)) {
            replaceFirstKey(key, KeyCode::KEY_NONE);
            sendKeyboardReport();
        }
    }

    void releaseAllKeys() {
        modifiers = 0x00;
        for (auto& key : keys) {
            key = KeyCode::KEY_NONE;
        }
        sendKeyboardReport();
    }

 private:
    struct Report {
        BYTE reportId;
        BYTE modifiers;
        BYTE _reserved;
        BYTE keyCodes[6];
    };

    static const BYTE REPORT_ID = 0x04;

    bool canPressKey(KeyCode key) const {
        auto begin = std::begin(keys);
        auto end = std::end(keys);
        bool isPressed = std::find(begin, end, key) != end;
        bool hasSpace = std::find(begin, end, KeyCode::KEY_NONE) != end;
        return !isPressed && hasSpace;
    }

    bool canReleaseKey(KeyCode key) const {
        auto begin = std::begin(keys);
        auto end = std::end(keys);
        bool isPressed = std::find(begin, end, key) != end;
        return isPressed;
    }

    void replaceFirstKey(KeyCode oldKey, KeyCode newKey) {
        auto begin = std::begin(keys);
        auto end = std::end(keys);
        auto keyPtr = std::find(begin, end, oldKey);
        if (keyPtr == end) {
            throw std::runtime_error{ "KEYCODE_DOES_NOT_EXIST" };
        }
        *keyPtr = newKey;
    }

    void sendKeyboardReport() {
        Report report;
        report.reportId = REPORT_ID;
        report.modifiers = (BYTE)modifiers;
        report._reserved = 0x00;
        std::memcpy(report.keyCodes, keys, 6);

        setOutputReport(&report, static_cast<DWORD>(sizeof(Report)));
    }

    unsigned char modifiers = 0x00;
    KeyCode keys[6] = { KeyCode::KEY_NONE };
    const HIDKeyboard& keyboard;
};

HIDKeyboard::HIDKeyboard() : impl(new Impl(*this)) {
    impl->initialize();
}

HIDKeyboard::~HIDKeyboard() {
    releaseAllKeys();
    impl->abort();
}

bool HIDKeyboard::isKeyPressed(KeyCode key) const {
    int virtualKey = getVirtualKey(key);
    return GetKeyState(virtualKey) & 0x80;
}

bool HIDKeyboard::isKeyToggled(KeyCode key) const {
    int virtualKey = getVirtualKey(key);
    return GetKeyState(virtualKey) & 0x01;
}

void HIDKeyboard::pressKey(KeyCode key) {
    if (isModifier(key)) {
        impl->pressModifier(key);
    } else {
        impl->pressKey(key);
    }
}

void HIDKeyboard::releaseKey(KeyCode key) {
    if (isModifier(key)) {
        impl->releaseModifier(key);
    } else {
        impl->releaseKey(key);
    }
}

void HIDKeyboard::releaseAllKeys() {
    impl->releaseAllKeys();
}
}  // namespace Impl
}  // namespace AutoMacro
