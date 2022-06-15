#include "AutoMacroTest/History/HistoryAssert.h"

#include <string>
#include <vector>

#include "CppUnitTest.h"
#include <AutoMacro/History/History.h>

namespace AutoMacro {
namespace History {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}

void HistoryAssert::areEqual(
    const History& history,
    std::string message) {
    Assert::AreEqual(message, history.message);
    Assert::AreEqual(static_cast<size_t>(0), history.pointers.size());
}

void HistoryAssert::durationIsInRange(
    const History& start,
    const History& last,
    int lowerb,
    int upperb) {
    using std::chrono::duration_cast;
    using std::chrono::milliseconds;
    auto duration = duration_cast<milliseconds>(last.time - start.time);
    Assert::IsTrue(lowerb < duration.count() && duration.count() < upperb);
}

void HistoryAssert::AllDurationAreInRange(
    const Histories& histoies,
    std::vector<int> expectedTimes,
    int tolerence) {
    Assert::AreEqual(expectedTimes.size(), histoies.size() - 1);
    for (int i = 0; i < expectedTimes.size() - 1; i++) {
        durationIsInRange(
            histoies[i],
            histoies[i + 1],
            expectedTimes[i],
            expectedTimes[i] + tolerence);
    }
}
}  // namespace History
}  // namespace AutoMacro
