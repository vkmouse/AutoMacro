#pragma once
#include <memory>

#include "AutoMacro/Core/Command/CommandParameter.h"
#include "AutoMacro/Core/Kvm/Kvm.h"

namespace AutoMacro {
class Command {
 public:
    explicit Command(CommandParameter* p)
        : kvm_(p->kvm),
          delayBeforeCommand(p->delayBeforeCommand),
          delayAfterCommand(p->delayAfterCommand) {
    }

    virtual void execute() {
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
