#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
class MouseTest {
 protected:
    MouseTest(int delay, int moveTolerance) : moveTolerance(moveTolerance) {}

    virtual std::shared_ptr<Mouse> createMouse() = 0;

    void TestMethodInitialize();
    void TestMouseButtonDownAndUp();
    void TestReleaseAllButtons();
    void TestMouseMove();

 private:
    static void TestButtonDownAndUp(
        std::shared_ptr<Mouse> mouse,
        MouseButton button);

    std::shared_ptr<Mouse> mouse = nullptr;
    int moveTolerance;
};
}  // namespace AutoMacro
