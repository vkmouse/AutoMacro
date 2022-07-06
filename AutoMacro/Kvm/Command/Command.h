#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Kvm/Command/DesktopSwitchCommandParameter.h"
#include "AutoMacro/Kvm/Command/MouseClickCommandParameter.h"
#include "AutoMacro/Kvm/Command/SendKeyCommandParameter.h"
#include "AutoMacro/Kvm/Command/ShortCutCommandParameter.h"

namespace AutoMacro {
namespace Factory {
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    DesktopSwitchCommandParameter* parameter);
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    SendKeyCommandParameter* parameter);
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    ShortcutCommandParameter* parameter);
DLL_EXPORTS std::shared_ptr<Command> createCommand(
    MouseClickCommandParameter* parameter);

DLL_EXPORTS std::shared_ptr<TCommand<void>> createTCommand(
    DesktopSwitchCommandParameter* parameter);
DLL_EXPORTS std::shared_ptr<TCommand<void>> createTCommand(
    SendKeyCommandParameter* parameter);
DLL_EXPORTS std::shared_ptr<TCommand<void>> createTCommand(
    ShortcutCommandParameter* parameter);
DLL_EXPORTS std::shared_ptr<TCommand<void>> createTCommand(
    MouseClickCommandParameter* parameter);
}  // namespace Factory
}  // namespace AutoMacro
