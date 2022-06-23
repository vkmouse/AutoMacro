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
    destination(p->destination),
    delayBetweemEachSwitch(p->delayBetweemEachSwitch) {
}

void DesktopSwitchCommand::executeCommand() {
    if (numDesktops != globalNumDesktops) {
        resetDesktop(numDesktops);
    }

    int times = destination - currentDesktop;
    if (times > 0) {
        switchToNext(times);
    } else if (times < 0) {
        switchToPrevious(times);
    }
}

int DesktopSwitchCommand::globalNumDesktops = -1;
int DesktopSwitchCommand::currentDesktop = -1;
void DesktopSwitchCommand::resetDesktop(int numDesktops) {
    globalNumDesktops = numDesktops;
    switchToPrevious(numDesktops - 1);
    currentDesktop = 1;
}

void DesktopSwitchCommand::switchToNext(int times) {
    ShortcutCommandParameter p(keyboard(), {
        KeyCode::KEY_LCTRL,
        KeyCode::KEY_LMETA,
        KeyCode::KEY_RIGHT });
    p.delayBetweenEachPressKey = 0;
    p.delayBetweenEachReleaseKey = 0;
    p.delayBetweenPressKeyAndReleaseKey = 1;
    p.repeatTimes = times;
    p.delayBetweenRepeatitions = delayBetweemEachSwitch;
    Factory::createCommand(&p)->execute();
    currentDesktop = currentDesktop + times;
}

void DesktopSwitchCommand::switchToPrevious(int times) {
    ShortcutCommandParameter p(keyboard(), {
        KeyCode::KEY_LCTRL,
        KeyCode::KEY_LMETA,
        KeyCode::KEY_LEFT });
    p.delayBetweenEachPressKey = 0;
    p.delayBetweenEachReleaseKey = 0;
    p.delayBetweenPressKeyAndReleaseKey = 1;
    p.repeatTimes = times;
    p.delayBetweenRepeatitions = delayBetweemEachSwitch;
    Factory::createCommand(&p)->execute();
    currentDesktop = currentDesktop - times;
}
}  // namespace Impl
}  // namespace Command
}  // namespace AutoMacro
