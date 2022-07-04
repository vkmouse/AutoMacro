#pragma once
#include "AutoMacro/Core/Command/Command.h"
#include "AutoMacro/Core/Command/KvmCommandParameter.h"
#include "AutoMacro/Core/Kvm/Kvm.h"

namespace AutoMacro {
class DLL_EXPORTS KvmCommand : public Command {
 public:
    explicit KvmCommand(KvmCommandParameter* p);

    virtual void execute();

 protected:
    virtual void executeCommand() = 0;

    const Kvm& kvm();
    void pressKey(KeyCode key);
    void releaseKey(KeyCode key);
    void releaseAllKeys();
    void mouseDown(MouseButton button);
    void mouseUp(MouseButton button);
    void mouseMove(int x, int y);
    void releaseAllButtons();
    Image takeSnapshot();
    void sleep(int ms);

 private:
    const Kvm& kvm_;
    int delayBeforeCommand_;
    int delayAfterCommand_;
};
}  // namespace AutoMacro
