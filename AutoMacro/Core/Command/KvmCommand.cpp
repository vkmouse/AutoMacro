#include "AutoMacro/Core/Command/KvmCommand.h"

namespace AutoMacro {
KvmCommand::KvmCommand(KvmCommandParameter* p)
    : kvm_(p->kvm),
      delayBeforeCommand_(p->delayBeforeCommand),
      delayAfterCommand_(p->delayAfterCommand) {
}

void KvmCommand::execute() {
    sleep(delayBeforeCommand_);
    executeCommand();
    sleep(delayAfterCommand_);
}

const Kvm& KvmCommand::kvm() {
    return kvm_;
}

void KvmCommand::pressKey(KeyCode key) {
    kvm_.keyboard->pressKey(key);
}

void KvmCommand::releaseKey(KeyCode key) {
    kvm_.keyboard->releaseKey(key);
}

void KvmCommand::releaseAllKeys() {
    kvm_.keyboard->releaseAllKeys();
}

void KvmCommand::mouseDown(MouseButton button) {
    kvm_.mouse->mouseDown(button);
}

void KvmCommand::mouseUp(MouseButton button) {
    kvm_.mouse->mouseUp(button);
}

void KvmCommand::mouseMove(int x, int y) {
    kvm_.mouse->mouseMove(x, y);
}

void KvmCommand::releaseAllButtons() {
    kvm_.mouse->releaseAllButtons();
}

Image KvmCommand::takeSnapshot() {
    return kvm_.videoCapture->takeSnapshot();
}

void KvmCommand::sleep(int ms) {
    kvm_.delay->execute(ms);
}
}  // namespace AutoMacro
