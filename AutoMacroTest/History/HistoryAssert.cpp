#include "AutoMacroTest/History/HistoryAssert.h"

#include <string>

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
}  // namespace History
}  // namespace AutoMacro
