#include "AutoMacro/History/History/Histories.h"

#include <chrono>
#include <string>
#include <vector>

#include "AutoMacro/History/History/History.h"

namespace AutoMacro {
namespace History {
void Histories::record(std::string message) {
    record(message, {});
}

void Histories::record(std::string message, std::vector<void*> pointers) {
    History history;
    history.time = std::chrono::high_resolution_clock::now();
    history.message = message;
    history.pointers = pointers;
    push_back(history);
}
}  // namespace History
}  // namespace AutoMacro
