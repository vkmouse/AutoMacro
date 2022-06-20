#pragma once
#include "AutoMacro/Core/pch.h"

namespace AutoMacro {
enum class KeyCode : unsigned char {
    KEY_NONE = 0x00,  // No key pressed

    KEY_A = 0x04,  // Keyboard a and A
    KEY_B = 0x05,  // Keyboard b and B
    KEY_C = 0x06,  // Keyboard c and C
    KEY_D = 0x07,  // Keyboard d and D
    KEY_E = 0x08,  // Keyboard e and E
    KEY_F = 0x09,  // Keyboard f and F
    KEY_G = 0x0a,  // Keyboard g and G
    KEY_H = 0x0b,  // Keyboard h and H
    KEY_I = 0x0c,  // Keyboard i and I
    KEY_J = 0x0d,  // Keyboard j and J
    KEY_K = 0x0e,  // Keyboard k and K
    KEY_L = 0x0f,  // Keyboard l and L
    KEY_M = 0x10,  // Keyboard m and M
    KEY_N = 0x11,  // Keyboard n and N
    KEY_O = 0x12,  // Keyboard o and O
    KEY_P = 0x13,  // Keyboard p and P
    KEY_Q = 0x14,  // Keyboard q and Q
    KEY_R = 0x15,  // Keyboard r and R
    KEY_S = 0x16,  // Keyboard s and S
    KEY_T = 0x17,  // Keyboard t and T
    KEY_U = 0x18,  // Keyboard u and U
    KEY_V = 0x19,  // Keyboard v and V
    KEY_W = 0x1a,  // Keyboard w and W
    KEY_X = 0x1b,  // Keyboard x and X
    KEY_Y = 0x1c,  // Keyboard y and Y
    KEY_Z = 0x1d,  // Keyboard z and Z

    KEY_1 = 0x1e,  // Keyboard 1 and !
    KEY_2 = 0x1f,  // Keyboard 2 and @
    KEY_3 = 0x20,  // Keyboard 3 and #
    KEY_4 = 0x21,  // Keyboard 4 and $
    KEY_5 = 0x22,  // Keyboard 5 and %
    KEY_6 = 0x23,  // Keyboard 6 and ^
    KEY_7 = 0x24,  // Keyboard 7 and &
    KEY_8 = 0x25,  // Keyboard 8 and *
    KEY_9 = 0x26,  // Keyboard 9 and (
    KEY_0 = 0x27,  // Keyboard 0 and )

    KEY_ENTER = 0x28,  // Keyboard Return (ENTER)
    KEY_ESC = 0x29,  // Keyboard ESCAPE
    KEY_BACKSPACE = 0x2a,  // Keyboard DELETE (Backspace)
    KEY_TAB = 0x2b,  // Keyboard Tab
    KEY_SPACE = 0x2c,  // Keyboard Spacebar
    KEY_MINUS = 0x2d,  // Keyboard - and _
    KEY_EQUAL = 0x2e,  // Keyboard = and +
    KEY_LEFTBRACE = 0x2f,  // Keyboard [ and {
    KEY_RIGHTBRACE = 0x30,  // Keyboard ] and }
    KEY_BACKSLASH = 0x31,  // Keyboard \ and |
    KEY_HASHTILDE = 0x32,  // Keyboard Non-US # and ~
    KEY_SEMICOLON = 0x33,  // Keyboard ; and :
    KEY_APOSTROPHE = 0x34,  // Keyboard ' and "
    KEY_GRAVE = 0x35,  // Keyboard ` and ~
    KEY_COMMA = 0x36,  // Keyboard , and <
    KEY_DOT = 0x37,  // Keyboard . and >
    KEY_SLASH = 0x38,  // Keyboard / and ?
    KEY_CAPSLOCK = 0x39,  // Keyboard Caps Lock

    KEY_F1 = 0x3a,  // Keyboard F1
    KEY_F2 = 0x3b,  // Keyboard F2
    KEY_F3 = 0x3c,  // Keyboard F3
    KEY_F4 = 0x3d,  // Keyboard F4
    KEY_F5 = 0x3e,  // Keyboard F5
    KEY_F6 = 0x3f,  // Keyboard F6
    KEY_F7 = 0x40,  // Keyboard F7
    KEY_F8 = 0x41,  // Keyboard F8
    KEY_F9 = 0x42,  // Keyboard F9
    KEY_F10 = 0x43,  // Keyboard F10
    KEY_F11 = 0x44,  // Keyboard F11
    KEY_F12 = 0x45,  // Keyboard F12

    KEY_SYSRQ = 0x46,  // Keyboard Print Screen
    KEY_SCROLLLOCK = 0x47,  // Keyboard Scroll Lock
    KEY_PAUSE = 0x48,  // Keyboard Pause
    KEY_INSERT = 0x49,  // Keyboard Insert
    KEY_HOME = 0x4a,  // Keyboard Home
    KEY_PAGEUP = 0x4b,  // Keyboard Page Up
    KEY_DELETE = 0x4c,  // Keyboard Delete Forward
    KEY_END = 0x4d,  // Keyboard End
    KEY_PAGEDOWN = 0x4e,  // Keyboard Page Down
    KEY_RIGHT = 0x4f,  // Keyboard Right Arrow
    KEY_LEFT = 0x50,  // Keyboard Left Arrow
    KEY_DOWN = 0x51,  // Keyboard Down Arrow
    KEY_UP = 0x52,  // Keyboard Up Arrow

    KEY_NUMLOCK = 0x53,  // Keyboard Num Lock and Clear
    KEY_KPSLASH = 0x54,  // Keypad /
    KEY_KPASTERISK = 0x55,  // Keypad *
    KEY_KPMINUS = 0x56,  // Keypad -
    KEY_KPPLUS = 0x57,  // Keypad +
    KEY_KPENTER = 0x58,  // Keypad ENTER
    KEY_KP1 = 0x59,  // Keypad 1 and End
    KEY_KP2 = 0x5a,  // Keypad 2 and Down Arrow
    KEY_KP3 = 0x5b,  // Keypad 3 and PageDn
    KEY_KP4 = 0x5c,  // Keypad 4 and Left Arrow
    KEY_KP5 = 0x5d,  // Keypad 5
    KEY_KP6 = 0x5e,  // Keypad 6 and Right Arrow
    KEY_KP7 = 0x5f,  // Keypad 7 and Home
    KEY_KP8 = 0x60,  // Keypad 8 and Up Arrow
    KEY_KP9 = 0x61,  // Keypad 9 and Page Up
    KEY_KP0 = 0x62,  // Keypad 0 and Insert
    KEY_KPDOT = 0x63,  // Keypad . and Delete

    KEY_102ND = 0x64,  // Keyboard Non-US \ and |
    KEY_COMPOSE = 0x65,  // Keyboard Application

    KEY_LEFTCTRL = 0xe0,  // Keyboard Left Control
    KEY_LEFTSHIFT = 0xe1,  // Keyboard Left Shift
    KEY_LEFTALT = 0xe2,  // Keyboard Left Alt
    KEY_LEFTMETA = 0xe3,  // Keyboard Left GUI
    KEY_RIGHTCTRL = 0xe4,  // Keyboard Right Control
    KEY_RIGHTSHIFT = 0xe5,  // Keyboard Right Shift
    KEY_RIGHTALT = 0xe6,  // Keyboard Right Alt
    KEY_RIGHTMETA = 0xe7,  // Keyboard Right GUI
};

class DLL_EXPORTS Keyboard {
 public:
    virtual bool isKeyPressed(KeyCode key) const = 0;
    virtual bool isKeyToggled(KeyCode key) const = 0;

    virtual void pressKey(KeyCode key) = 0;
    virtual void releaseKey(KeyCode key) = 0;
    virtual void releaseAllKeys() = 0;
};
}  // namespace AutoMacro
