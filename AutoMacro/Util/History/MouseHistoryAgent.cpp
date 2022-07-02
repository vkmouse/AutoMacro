#include "AutoMacro/Util/History/MouseHistoryAgent.h"

#include <memory>

#include "AutoMacro/Util/History/Histories.h"

namespace AutoMacro {
namespace Impl {
MouseHistoryAgent::MouseHistoryAgent(
    std::shared_ptr<Mouse> mouse, Histories* histories)
    : mouse(mouse), histories(histories) {
}

Point MouseHistoryAgent::getCurrentPosition() const {
    return mouse->getCurrentPosition();
}

bool MouseHistoryAgent::isMouseButtonDown(MouseButton button) const {
    return mouse->isMouseButtonDown(button);
}

void MouseHistoryAgent::mouseDown(MouseButton button) {
    mouse->mouseDown(button);
    histories->record("mouseDown", button);
}

void MouseHistoryAgent::mouseUp(MouseButton button) {
    mouse->mouseUp(button);
    histories->record("mouseUp", button);
}

void MouseHistoryAgent::mouseMove(int x, int y) {
    mouse->mouseMove(x, y);
    histories->record("mouseMove", x, y);
}

void MouseHistoryAgent::releaseAllButtons() {
    mouse->releaseAllButtons();
    histories->record("releaseAllButtons");
}
}  // namespace Impl
}  // namespace AutoMacro
