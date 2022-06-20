#include "AutoMacro/Command/Command/WaitForItemCommand.h"

#include <memory>

#include "AutoMacro/Command/Command/CommandParameter.h"
#include "AutoMacro/Detection/Detection.h"

namespace AutoMacro {
namespace Command {
WaitForItemCommand::WaitForItemCommand(WaitForItemCommandParameter* p) :
    WaitForCommand(p),
    detector(p->detector),
    index(p->index),
    threshold(p->threshold) {
}

bool WaitForItemCommand::testExpression() {
    auto results = detector->detect(videoCapture()->takeSnapshot());
    return Detection::itemExists(results, index, threshold) == waitForExists();
}
}  // namespace Command
}  // namespace AutoMacro
