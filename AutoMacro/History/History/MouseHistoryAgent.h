#pragma once
#include <memory>
#include <string>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/History/History/Histories.h"

namespace AutoMacro {
namespace History {
namespace Impl {
class MouseHistoryAgent : public Mouse {
 public:
    MouseHistoryAgent(
        std::shared_ptr<Mouse> mouse,
        Histories* histories);

    virtual Point getCurrentPosition() const;
    virtual bool isMouseButtonDown(MouseButton button) const;

    virtual void mouseDown(MouseButton button);
    virtual void mouseUp(MouseButton button);
    virtual void mouseMove(int x, int y);
    virtual void releaseAllButtons();

 private:
    std::shared_ptr<Mouse> mouse;
    Histories* histories;
};
}  // namespace Impl
}  // namespace History
}  // namespace AutoMacro
