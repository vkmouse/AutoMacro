#include "AutoMacroTest/Mouse/MockMouseTest.h"

#include "CppUnitTest.h"
#include <AutoMacro/Mouse/Mouse.h>

namespace AutoMacro {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
Mouse* mouse;
void assertMouseButtonIsDown(MouseButton button) {
    Assert::AreEqual(true, mouse->isMouseButtonDown(button));
}

void assertMouseButtonIsUp(MouseButton button) {
    Assert::AreEqual(false, mouse->isMouseButtonDown(button));
}
}  // namespace

void __stdcall MockMouseTest::initialize() {
    mouse = Factory::createMockMouse();
}

void __stdcall MockMouseTest::cleanup() {
    delete(mouse);
}

void MockMouseTest::TestMockMouseDownAndUp() {
    assertMouseButtonIsUp(MouseButton::BUTTON_LEFT);

    mouse->mouseDown(MouseButton::BUTTON_LEFT);
    assertMouseButtonIsDown(MouseButton::BUTTON_LEFT);

    mouse->mouseUp(MouseButton::BUTTON_LEFT);
    assertMouseButtonIsUp(MouseButton::BUTTON_LEFT);
}

void MockMouseTest::TestMockMouseReleaseAllKeys() {
    assertMouseButtonIsUp(MouseButton::BUTTON_LEFT);
    assertMouseButtonIsUp(MouseButton::BUTTON_RIGHT);
    assertMouseButtonIsUp(MouseButton::BUTTON_MIDDLE);

    mouse->mouseDown(MouseButton::BUTTON_LEFT);
    mouse->mouseDown(MouseButton::BUTTON_RIGHT);
    mouse->mouseDown(MouseButton::BUTTON_MIDDLE);
    assertMouseButtonIsDown(MouseButton::BUTTON_LEFT);
    assertMouseButtonIsDown(MouseButton::BUTTON_RIGHT);
    assertMouseButtonIsDown(MouseButton::BUTTON_MIDDLE);

    mouse->releaseAllButtons();
    assertMouseButtonIsUp(MouseButton::BUTTON_LEFT);
    assertMouseButtonIsUp(MouseButton::BUTTON_RIGHT);
    assertMouseButtonIsUp(MouseButton::BUTTON_MIDDLE);
}

void MockMouseTest::TestMockMouseMove() {
    Point expected(0, 0);
    mouse->mouseMove(0, 0);
    Assert::IsTrue(expected == mouse->getCurrentPosition());

    expected = Point(500, 500);
    mouse->mouseMove(500, 500);
    Assert::IsTrue(expected == mouse->getCurrentPosition());
}
}  // namespace AutoMacro
