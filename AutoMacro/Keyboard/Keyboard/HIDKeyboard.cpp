#include "AutoMacro/Keyboard/Keyboard/HIDKeyboard.h"

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Impl {
bool HIDKeyboard::isKeyPressed(KeyCode key) const {
	return false;
}

bool HIDKeyboard::isKeyToggled(KeyCode key) const {
	return false;
}

void HIDKeyboard::pressKey(KeyCode key) {
}

void HIDKeyboard::releaseKey(KeyCode key) {
}

void HIDKeyboard::releaseAllKeys() {
}
}  // namespace Impl
}  // namespace AutoMacro
