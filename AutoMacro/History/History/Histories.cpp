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

void Histories::record(std::string message, std::vector<void*> parameters) {
    History history(message, parameters);
    push_back(history);
}

bool Histories::allDurationsAreInRange(
    std::vector<int> expectedTimes, int tolerence) const {
    if (expectedTimes.size() != size() - 1) {
        return false;
    }

    for (int i = 0; i < expectedTimes.size() - 1; i++) {
        int lowerb = expectedTimes[i];
        int upperb = expectedTimes[i] + tolerence;
        if (!History::durationIsInRange(at(i), at(i + 1), lowerb, upperb)) {
            return false;
        }
    }

    return true;
}
}  // namespace History
}  // namespace AutoMacro
