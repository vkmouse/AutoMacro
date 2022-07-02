#include "AutoMacro/Cv/Command/WaitForCommand.h"

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Cv/Command/WaitForCommandParameter.h"

namespace AutoMacro {
namespace Impl {
WaitForCommand::WaitForCommand(WaitForCommandParameter* p)
    : Command(p),
      delayBetweenRepeatitions_(p->delayBetweenRepeatitions),
      waitForExists_(p->waitForExists) {
}

void WaitForCommand::executeCommand() {
    while (!testExpression()) {
        sleep(delayBetweenRepeatitions_);
    }
}

bool WaitForCommand::waitForExists() const {
    return waitForExists_;
}
}  // namespace Impl
}  // namespace AutoMacro
