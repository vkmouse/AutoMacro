#include "AutoMacro/Kvm/Command/DesktopSwitchCommand.h"

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Kvm/Command/DesktopSwitchCommandParameter.h"
#include "AutoMacro/Kvm/Command/ShortCutCommand.h"
#include "AutoMacro/Kvm/Command/ShortCutCommandParameter.h"

namespace AutoMacro {
namespace Impl {
DesktopSwitchCommand::DesktopSwitchCommand(
    DesktopSwitchCommandParameter* p)
    : Command(p),
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
    if (times > 0) {
        ShortcutCommandParameter p(kvm(),
            { KeyCode::KEY_LCTRL, KeyCode::KEY_LMETA, KeyCode::KEY_RIGHT });
        p.delayBetweenEachPressKey = 0;
        p.delayBetweenEachReleaseKey = 0;
        p.delayBetweenPressKeyAndReleaseKey = 1;
        p.repeatTimes = times;
        p.delayBetweenRepeatitions = delayBetweemEachSwitch;
        ShortcutCommand cmd(&p);
        cmd.execute();
        currentDesktop = currentDesktop + times;
    }
}

void DesktopSwitchCommand::switchToPrevious(int times) {
    if (times > 0) {
        ShortcutCommandParameter p(kvm(),
            { KeyCode::KEY_LCTRL, KeyCode::KEY_LMETA, KeyCode::KEY_LEFT });
        p.delayBetweenEachPressKey = 0;
        p.delayBetweenEachReleaseKey = 0;
        p.delayBetweenPressKeyAndReleaseKey = 1;
        p.repeatTimes = times;
        p.delayBetweenRepeatitions = delayBetweemEachSwitch;
        ShortcutCommand cmd(&p);
        cmd.execute();
        currentDesktop = currentDesktop - times;
    }
}
}  // namespace Impl
}  // namespace AutoMacro
