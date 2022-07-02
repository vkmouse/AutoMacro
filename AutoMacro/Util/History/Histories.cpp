#include "AutoMacro/Util/History/Histories.h"

#include <chrono>
#include <string>
#include <vector>

#include "AutoMacro/Util/History/History.h"

namespace AutoMacro {
void Histories::record(std::string message) {
    record(message, {});
}

void Histories::record(std::string message, std::vector<void*> parameters) {
    History history(message, parameters);
    push_back(history);
}
}  // namespace AutoMacro
