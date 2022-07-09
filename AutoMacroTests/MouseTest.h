#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace KvmTest {
class MouseTest {
 protected:
    explicit MouseTest(int moveTolerance) : moveTolerance(moveTolerance) {}

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
}  // namespace KvmTest
}  // namespace AutoMacro
