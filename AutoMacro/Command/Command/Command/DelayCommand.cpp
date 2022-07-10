#include "AutoMacro/Command/Command/Command/DelayCommand.h"

#include "AutoMacro/Command/Command/Parameter/DelayCommandParameter.h"

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
