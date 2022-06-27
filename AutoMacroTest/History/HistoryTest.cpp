#include "AutoMacroTest/History/HistoryTest.h"

#include "AutoMacro/History/History.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace History {
namespace {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;
}  // namespace

void HistoryTest::TestHistories() {
    Histories histories;
    histories.record("first record");
    Assert::IsTrue(histories.back().equals("first record"));

    histories.record("record", 1, 1.34f, 46.461);
    Assert::IsTrue(histories.back().equals("record", 1, 1.34f, 46.461));

    enum Enum1 { ENUM11, ENUM12 };
    enum Enum2 { ENUM22 };
    histories.record("record", ENUM11, ENUM12, ENUM22);
    Assert::IsTrue(histories.back().equals("record", ENUM11, ENUM12, ENUM22));
}
}  // namespace History
}  // namespace AutoMacro
