#include "AutoMacro/KbdMou/KbdMou/MockKeyboard.h"

#include <vector>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Impl {
std::vector<KeyCode> pressedList;
std::vector<KeyCode> toggledList;

bool find(const std::vector<KeyCode>& list, KeyCode key) {
    auto iterator = std::find(list.begin(), list.end(), key);
    bool found = iterator != list.end();
    return found;
}

void add(std::vector<KeyCode>* list, KeyCode key) {
    list->push_back(key);
}

void remove(std::vector<KeyCode>* list, KeyCode key) {
    auto iterator = std::find(list->begin(), list->end(), key);
    bool found = iterator != list->end();
    if (found) {
        list->erase(iterator);
    }
}

void clear(std::vector<KeyCode>* list) {
    list->clear();
}

bool MockKeyboard::isKeyPressed(KeyCode key) const {
    return find(pressedList, key);
}

bool MockKeyboard::isKeyToggled(KeyCode key) const {
    return find(toggledList, key);
}

void MockKeyboard::pressKey(KeyCode key) {
    if (!isKeyPressed(key)) {
        add(&pressedList, key);

        if (isKeyToggled(key)) {
            remove(&toggledList, key);
        } else {
            add(&toggledList, key);
        }
    }
}

void MockKeyboard::releaseKey(KeyCode key) {
    if (isKeyPressed(key)) {
        remove(&pressedList, key);
    }
}

void MockKeyboard::releaseAllKeys() {
    clear(&pressedList);
}
}  // namespace Impl
}  // namespace AutoMacro
