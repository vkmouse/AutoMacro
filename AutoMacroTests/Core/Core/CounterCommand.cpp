#include "AutoMacroTests/Core/Core/CounterCommand.h"

namespace AutoMacro {
namespace CoreTest {
CounterCommand::CounterCommand(CounterCommandParameter* p)
    : Command(p), count_(p->count) {
}
void CounterCommand::executeCommand() {
    (*count_)++;
}
}  // namespace CoreTest
}  // namespace AutoMacro
