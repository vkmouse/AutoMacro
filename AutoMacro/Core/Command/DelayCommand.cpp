#include "AutoMacro/Core/Command/DelayCommand.h"

#include <memory>

#include "AutoMacro/Core/Command/DelayCommandParameter.h"

namespace AutoMacro {
namespace Impl {
DelayCommand::DelayCommand(DelayCommandParameter* p)
    : KvmCommand(p), ms_(p->ms) {
}

void DelayCommand::executeCommand() {
    sleep(ms_);
}
}  // namespace Impl
}  // namespace AutoMacro
