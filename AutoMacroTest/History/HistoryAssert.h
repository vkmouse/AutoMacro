#pragma once
#include <string>
#include <vector>

#include "CppUnitTest.h"
#include <AutoMacro/History/History.h>

namespace AutoMacro {
namespace History {
class HistoryAssert {
 public:
    static void areEqual(
        const History& history,
        std::string message);

    template <typename T>
    static void areEqual(
        const History& history,
        std::string message,
        T parameter) {
        using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
        Assert::AreEqual(message, history.message);
        T* ptr = reinterpret_cast<T*>(history.pointers.back());
        Assert::IsTrue(parameter == *ptr);
    }

    template <typename T, typename ...Ts>
    static void areEqual(
        const History& history,
        std::string message,
        T parameter,
        Ts... parameters) {
        using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
        size_t lastIndex = history.pointers.size() - 1;
        size_t currentIndex = lastIndex - sizeof...(parameters);
        T* ptr = reinterpret_cast<T*>(history.pointers.at(currentIndex));
        Assert::IsTrue(parameter == *ptr);
        HistoryAssert::areEqual(history, message, parameters...);
    }

    static void durationIsInRange(
        const History& start,
        const History& last,
        int lowerb,
        int upperb);

    static void AllDurationAreInRange(
        const Histories& histoies,
        std::vector<int> expectedTimes,
        int tolerence);
};
}  // namespace History
}  // namespace AutoMacro
