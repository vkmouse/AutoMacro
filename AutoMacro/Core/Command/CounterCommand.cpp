#include "AutoMacro/Core/Command/CounterCommand.h"

namespace AutoMacro {
namespace Impl {
CounterCommand::CounterCommand(CounterCommandParameter* p)
    : count_(p->count) {
}

void CounterCommand::execute() {
    (*count_)++;
}
}  // namespace Impl
}  // namespace AutoMacro
