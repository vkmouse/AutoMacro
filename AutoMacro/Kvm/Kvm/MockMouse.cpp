#include "AutoMacro/Kvm/Kvm/MockMouse.h"

#include <vector>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Impl {
std::vector<MouseButton> pressedList;
int currentX = 0;
int currentY = 0;

bool find(const std::vector<MouseButton>& list, MouseButton button) {
    auto iterator = std::find(list.begin(), list.end(), button);
    bool found = iterator != list.end();
    return found;
}

void add(std::vector<MouseButton>* list, MouseButton button) {
    list->push_back(button);
}

void remove(std::vector<MouseButton>* list, MouseButton button) {
    auto iterator = std::find(list->begin(), list->end(), button);
    bool found = iterator != list->end();
    if (found) {
        list->erase(iterator);
    }
}

void clear(std::vector<MouseButton>* list) {
    list->clear();
}

bool MockMouse::isMouseButtonDown(MouseButton button) const {
    return find(pressedList, button);
}

Point MockMouse::getCurrentPosition() const {
    return { currentX, currentY };
}

void MockMouse::mouseDown(MouseButton button) {
    if (!isMouseButtonDown(button)) {
        add(&pressedList, button);
    }
}

void MockMouse::mouseUp(MouseButton button) {
    if (isMouseButtonDown(button)) {
        remove(&pressedList, button);
    }
}

void MockMouse::mouseMove(int x, int y) {
    currentX = x;
    currentY = y;
}

void MockMouse::releaseAllButtons() {
    clear(&pressedList);
}
}  // namespace Impl
}  // namespace AutoMacro
