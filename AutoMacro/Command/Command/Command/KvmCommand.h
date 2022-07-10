#pragma once
#include "AutoMacro/Core/Command/Command.h"
#include "AutoMacro/Core/Kvm/Kvm.h"
#include "AutoMacro/Command/Command/Parameter/KvmCommandParameter.h"

namespace AutoMacro {
template<class T>
class DLL_EXPORTS KvmCommand : public TCommand<T> {
 public:
    explicit KvmCommand(KvmCommandParameter* p)
        : kvm_(p->kvm),
          delayBeforeCommand_(p->delayBeforeCommand),
          delayAfterCommand_(p->delayAfterCommand) {
    }

    virtual T execute();

 protected:
    virtual T executeCommand() = 0;

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
    Kvm kvm_;
    int delayBeforeCommand_;
    int delayAfterCommand_;
};

template<>
inline void KvmCommand<void>::execute() {
    sleep(delayBeforeCommand_);
    executeCommand();
    sleep(delayAfterCommand_);
}

template<>
inline bool KvmCommand<bool>::execute() {
    sleep(delayBeforeCommand_);
    auto output = executeCommand();
    sleep(delayAfterCommand_);
    return output;
}
}  // namespace AutoMacro
