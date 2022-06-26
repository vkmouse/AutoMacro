#include "AutoMacroTest/KbdMou/MouseTest.h"

#include <Windows.h>
#include <memory>

#include "CppUnitTest.h"
#include <AutoMacro/KbdMou/KbdMou.h>

namespace AutoMacro {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

void MouseTest::TestMethodInitialize() {
    if (mouse == nullptr) {
        mouse = createMouse();
    }
    mouse->releaseAllButtons();
}

void MouseTest::TestMouseButtonDownAndUp() {
    TestButtonDownAndUp(mouse, MouseButton::BUTTON_LEFT);
    TestButtonDownAndUp(mouse, MouseButton::BUTTON_MIDDLE);
    TestButtonDownAndUp(mouse, MouseButton::BUTTON_RIGHT);
}

void MouseTest::TestReleaseAllButtons() {
    Assert::IsFalse(mouse->isMouseButtonDown(MouseButton::BUTTON_LEFT));
    Assert::IsFalse(mouse->isMouseButtonDown(MouseButton::BUTTON_RIGHT));
    Assert::IsFalse(mouse->isMouseButtonDown(MouseButton::BUTTON_MIDDLE));

    mouse->mouseDown(MouseButton::BUTTON_LEFT);
    mouse->mouseDown(MouseButton::BUTTON_RIGHT);
    mouse->mouseDown(MouseButton::BUTTON_MIDDLE);
    Assert::IsTrue(mouse->isMouseButtonDown(MouseButton::BUTTON_LEFT));
    Assert::IsTrue(mouse->isMouseButtonDown(MouseButton::BUTTON_RIGHT));
    Assert::IsTrue(mouse->isMouseButtonDown(MouseButton::BUTTON_MIDDLE));

    mouse->releaseAllButtons();
    Assert::IsFalse(mouse->isMouseButtonDown(MouseButton::BUTTON_LEFT));
    Assert::IsFalse(mouse->isMouseButtonDown(MouseButton::BUTTON_RIGHT));
    Assert::IsFalse(mouse->isMouseButtonDown(MouseButton::BUTTON_MIDDLE));
}

void MouseTest::TestMouseMove() {
    for (int i = 0; i < 100; i++) {
        int x = rand() % 1920;
        int y = rand() % 1080;
        mouse->mouseMove(x, y);
        auto actual = mouse->getCurrentPosition();
        Assert::IsTrue(x - moveTolerance <= actual.x);
        Assert::IsTrue(actual.x <= x + moveTolerance);
        Assert::IsTrue(y - moveTolerance <= actual.y);
        Assert::IsTrue(actual.y <= y + moveTolerance);
    }
}

void MouseTest::TestButtonDownAndUp(
    std::shared_ptr<Mouse> mouse,
    MouseButton button) {
    Assert::IsFalse(mouse->isMouseButtonDown(button));
    mouse->mouseDown(button);
    Assert::IsTrue(mouse->isMouseButtonDown(button));
    mouse->mouseUp(button);
    Assert::IsFalse(mouse->isMouseButtonDown(button));
}
}  // namespace AutoMacro
