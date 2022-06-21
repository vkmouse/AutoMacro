#include "AutoMacro/Command/Command/WaitForCommand.h"

#include <Windows.h>

#include "AutoMacro/Command/Command/CommandParameter.h"

namespace AutoMacro {
namespace Command {
namespace Impl {
WaitForCommand::WaitForCommand(WaitForCommandParameter* p) :
    Command(p),
    videoCapture_(p->videoCapture),
    delayBetweenRepeatitions_(p->delayBetweenRepeatitions),
    waitForExists_(p->waitForExists) {
}

void WaitForCommand::executeCommand() {
    while (!testExpression()) {
        Sleep(delayBetweenRepeatitions_);
    }
}

std::shared_ptr<VideoCapture> WaitForCommand::videoCapture() const {
    return videoCapture_;
}

bool WaitForCommand::waitForExists() const {
    return waitForExists_;
}
}  // namespace Impl
}  // namespace Command
}  // namespace AutoMacro
