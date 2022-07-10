#include "AutoMacro/Command/Command/Command/DesktopSwitchCommand.h"

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Parameter/DesktopSwitchCommandParameter.h"
#include "AutoMacro/Command/Command/Factory/ShortcutCommandFactory.h"

namespace AutoMacro {
namespace Impl {
DesktopSwitchCommand::DesktopSwitchCommand(
    DesktopSwitchCommandParameter* p)
    : KvmCommand(p),
      numDesktops(p->numDesktops),
      destination(p->destination),
      delayBetweemEachSwitch(p->delayBetweemEachSwitch),
      afterSwitchCommand(p->afterSwitchCommand) {
}

void DesktopSwitchCommand::executeCommand() {
    if (numDesktops != globalNumDesktops) {
        resetDesktop(numDesktops);
    }

    int times = destination - currentDesktop;
    if (times > 0) {
        switchToNext(abs(times));
    } else if (times < 0) {
        switchToPrevious(abs(times));
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
        auto cmd = Factory::createCommand(&p);
        cmd->execute();
        currentDesktop = currentDesktop + times;
        afterSwitchCommand->execute();
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
        auto cmd = Factory::createCommand(&p);
        cmd->execute();
        currentDesktop = currentDesktop - times;
        afterSwitchCommand->execute();
    }
}
}  // namespace Impl
}  // namespace AutoMacro
