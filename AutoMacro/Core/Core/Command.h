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
        : kvm_(p->kvm),
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

    const Kvm& kvm() { return kvm_; }

    void pressKey(KeyCode key) { kvm_.keyboard->pressKey(key); }
    void releaseKey(KeyCode key) { kvm_.keyboard->releaseKey(key); }
    void releaseAllKeys() { kvm_.keyboard->releaseAllKeys(); }
    void mouseDown(MouseButton button) { kvm_.mouse->mouseDown(button); }
    void mouseUp(MouseButton button) { kvm_.mouse->mouseUp(button); }
    void mouseMove(int x, int y) { kvm_.mouse->mouseMove(x, y); }
    void releaseAllButtons() { kvm_.mouse->releaseAllButtons(); }
    Image takeSnapshot() { return kvm_.videoCapture->takeSnapshot(); }
    void sleep(int ms) { kvm_.delay->execute(ms); }

 private:
    const Kvm& kvm_;
    int delayBeforeCommand;
    int delayAfterCommand;
};
}  // namespace AutoMacro
