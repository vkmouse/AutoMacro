#include "AutoMacroTest/Mouse/MockMouseTest.h"

#include <memory>

#include "CppUnitTest.h"
#include <AutoMacro/Mouse/Mouse.h>

namespace AutoMacro {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
void assertMouseButtonIsDown(std::shared_ptr<Mouse> mouse, MouseButton button) {
    Assert::AreEqual(true, mouse->isMouseButtonDown(button));
}

void assertMouseButtonIsUp(std::shared_ptr<Mouse> mouse, MouseButton button) {
    Assert::AreEqual(false, mouse->isMouseButtonDown(button));
}
}  // namespace

void MockMouseTest::TestMockMouseDownAndUp() {
    std::shared_ptr<Mouse> mouse = Factory::createMockMouse();

    assertMouseButtonIsUp(mouse, MouseButton::BUTTON_LEFT);

    mouse->mouseDown(MouseButton::BUTTON_LEFT);
    assertMouseButtonIsDown(mouse, MouseButton::BUTTON_LEFT);

    mouse->mouseUp(MouseButton::BUTTON_LEFT);
    assertMouseButtonIsUp(mouse, MouseButton::BUTTON_LEFT);
}

void MockMouseTest::TestMockMouseReleaseAllKeys() {
    std::shared_ptr<Mouse> mouse = Factory::createMockMouse();

    assertMouseButtonIsUp(mouse, MouseButton::BUTTON_LEFT);
    assertMouseButtonIsUp(mouse, MouseButton::BUTTON_RIGHT);
    assertMouseButtonIsUp(mouse, MouseButton::BUTTON_MIDDLE);

    mouse->mouseDown(MouseButton::BUTTON_LEFT);
    mouse->mouseDown(MouseButton::BUTTON_RIGHT);
    mouse->mouseDown(MouseButton::BUTTON_MIDDLE);
    assertMouseButtonIsDown(mouse, MouseButton::BUTTON_LEFT);
    assertMouseButtonIsDown(mouse, MouseButton::BUTTON_RIGHT);
    assertMouseButtonIsDown(mouse, MouseButton::BUTTON_MIDDLE);

    mouse->releaseAllButtons();
    assertMouseButtonIsUp(mouse, MouseButton::BUTTON_LEFT);
    assertMouseButtonIsUp(mouse, MouseButton::BUTTON_RIGHT);
    assertMouseButtonIsUp(mouse, MouseButton::BUTTON_MIDDLE);
}

void MockMouseTest::TestMockMouseMove() {
    std::shared_ptr<Mouse> mouse = Factory::createMockMouse();

    Point expected(0, 0);
    mouse->mouseMove(0, 0);
    Assert::IsTrue(expected == mouse->getCurrentPosition());

    expected = Point(500, 500);
    mouse->mouseMove(500, 500);
    Assert::IsTrue(expected == mouse->getCurrentPosition());
}
}  // namespace AutoMacro
