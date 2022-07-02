#include "AutoMacro/Util/History/DelayHistoryAgent.h"

#include <memory>

#include "AutoMacro/Util/History/Histories.h"

namespace AutoMacro {
namespace Impl {
DelayHistoryAgent::DelayHistoryAgent(
    std::shared_ptr<Delay> delay, Histories* histories)
    : delay(delay), histories(histories) {
}

void DelayHistoryAgent::execute(int ms) {
    delay->execute(ms);
    histories->record("delay", ms);
}
}  // namespace Impl
}  // namespace AutoMacro
