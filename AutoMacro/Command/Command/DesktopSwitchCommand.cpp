#include "AutoMacro/Command/Command/DesktopSwitchCommand.h"

#include <Windows.h>
#include <memory>

#include "AutoMacro/Command/Command.h"
#include "AutoMacro/Command/Command/CommandParameter.h"
#include "AutoMacro/KbdMou/KbdMou.h"

namespace AutoMacro {
namespace Command {
namespace Impl {
DesktopSwitchCommand::DesktopSwitchCommand(
    DesktopSwitchCommandParameter* p) :
    KeyboardCommand(p),
    numDesktops(p->numDesktops),
    destination(p->destination) {
}

void DesktopSwitchCommand::executeCommand() {
    if (numDesktops != globalNumDesktops) {
        resetDesktop(keyboard(), numDesktops);
    }

    int times = destination - currentDesktop;
    if (times > 0) {
        switchToNext(keyboard(), times);
    } else if (times < 0) {
        switchToPrevious(keyboard(), times);
    }
}

int DesktopSwitchCommand::globalNumDesktops = -1;
int DesktopSwitchCommand::currentDesktop = -1;
void DesktopSwitchCommand::resetDesktop(
    std::shared_ptr<Keyboard> keyboard, int numDesktops) {
    globalNumDesktops = numDesktops;
    switchToPrevious(keyboard, numDesktops - 1);
    currentDesktop = 1;
}

void DesktopSwitchCommand::switchToNext(
    std::shared_ptr<Keyboard> keyboard, int times) {
    ShortcutCommandParameter p(keyboard, {
        KeyCode::KEY_LEFTCTRL,
        KeyCode::KEY_LEFTMETA,
        KeyCode::KEY_RIGHT });
    p.delayBetweenEachPressKey = 0;
    p.delayBetweenEachReleaseKey = 0;
    p.delayBetweenPressKeyAndReleaseKey = 1;
    p.repeatTimes = times;
    Factory::createCommand(&p)->execute();
    currentDesktop = currentDesktop + times;
}

void DesktopSwitchCommand::switchToPrevious(
    std::shared_ptr<Keyboard> keyboard, int times) {
    ShortcutCommandParameter p(keyboard, {
        KeyCode::KEY_LEFTCTRL,
        KeyCode::KEY_LEFTMETA,
        KeyCode::KEY_LEFT });
    p.delayBetweenEachPressKey = 0;
    p.delayBetweenEachReleaseKey = 0;
    p.delayBetweenPressKeyAndReleaseKey = 1;
    p.repeatTimes = times;
    Factory::createCommand(&p)->execute();
    currentDesktop = currentDesktop - times;
}
}  // namespace Impl
}  // namespace Command
}  // namespace AutoMacro
