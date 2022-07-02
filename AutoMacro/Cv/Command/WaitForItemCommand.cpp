#include "AutoMacro/Cv/Command/WaitForItemCommand.h"

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Cv/Command/WaitForItemCommandParameter.h"
#include "AutoMacro/Util/Util.h"

namespace AutoMacro {
namespace Impl {
WaitForItemCommand::WaitForItemCommand(WaitForItemCommandParameter* p)
    : WaitForCommand(p),
      detector(p->detector),
      index(p->index),
      threshold(p->threshold) {
}

bool WaitForItemCommand::testExpression() {
    auto results = detector->detect(takeSnapshot());
    return Util::exists(results, threshold, index) == waitForExists();
}
}  // namespace Impl
}  // namespace AutoMacro
