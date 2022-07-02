#pragma once
#include <memory>

#include "AutoMacro/Core/Core/CommandParameter.h"
#include "AutoMacro/Core/Core/Delay.h"
#include "AutoMacro/Core/Core/Keyboard.h"
#include "AutoMacro/Core/Core/Mouse.h"
#include "AutoMacro/Core/Core/VideoCapture.h"

namespace AutoMacro {
class Command {
 public:
    explicit Command(CommandParameter* p)
        : keyboard_(p->keyboard),
          mouse_(p->mouse),
          videoCapture_(p->videoCapture),
          delay_(p->delay),
          delayBeforeCommand(p->delayBeforeCommand),
          delayAfterCommand(p->delayAfterCommand) {
    }

    void execute() {
        sleep(delayBeforeCommand);
        executeCommand();
        sleep(delayAfterCommand);
    }

 protected:
    virtual void executeCommand() = 0;

    std::shared_ptr<Keyboard> keyboard() { return keyboard_; }
    std::shared_ptr<Mouse> mouse() { return mouse_; }
    std::shared_ptr<VideoCapture> videoCapture() { return videoCapture_; }
    std::shared_ptr<Delay> delay() { return delay_; }

    void pressKey(KeyCode key) { keyboard_->pressKey(key); }
    void releaseKey(KeyCode key) { keyboard_->releaseKey(key); }
    void releaseAllKeys() { keyboard_->releaseAllKeys(); }
    void mouseDown(MouseButton button) { mouse_->mouseDown(button); }
    void mouseUp(MouseButton button) { mouse_->mouseUp(button); }
    void mouseMove(int x, int y) { mouse_->mouseMove(x, y); }
    void releaseAllButtons() { mouse_->releaseAllButtons(); }
    Image takeSnapshot() { return videoCapture_->takeSnapshot(); }
    void sleep(int ms) { delay_->execute(ms); }

 private:
    std::shared_ptr<Keyboard> keyboard_;
    std::shared_ptr<Mouse> mouse_;
    std::shared_ptr<VideoCapture> videoCapture_;
    std::shared_ptr<Delay> delay_;
    int delayBeforeCommand;
    int delayAfterCommand;
};
}  // namespace AutoMacro
