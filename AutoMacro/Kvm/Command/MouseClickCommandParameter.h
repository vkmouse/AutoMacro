#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
class MouseClickCommandParameter : public KvmCommandParameter {
 public:
    MouseClickCommandParameter(Kvm kvm, MouseButton button)
        : KvmCommandParameter(kvm), button(button) {}

    MouseClickCommandParameter(Kvm kvm, MouseButton button, int x, int y)
        : KvmCommandParameter(kvm), button(button), x(x), y(y) {
        enableMove = true;
    }

    MouseButton button;
    int delayBetweenMouseDownAndMouseUp = 0;
    int delayBetweenRepeatitions = 0;
    int repeatTimes = 1;

    bool enableMove = false;
    int x = 0;
    int y = 0;
    int delayBeforeMove = 0;
    int delayAfterMove = 0;
};
}  // namespace AutoMacro
