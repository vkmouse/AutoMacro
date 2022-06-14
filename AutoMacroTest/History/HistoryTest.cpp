#include "AutoMacroTest/History/HistoryTest.h"

#include "CppUnitTest.h"
#include <AutoMacro/History/History.h>
#include "AutoMacroTest/History/HistoryAssert.h"

namespace AutoMacro {
namespace History {
void HistoryTest::TestHistories() {
    Histories histories;
    histories.record("first record");
    HistoryAssert::areEqual(histories.back(), "first record");

    histories.record("record", 1, 1.34f, 46.461);
    HistoryAssert::areEqual(histories.back(), "record", 1, 1.34f, 46.461);

    enum Enum1 { ENUM11, ENUM12 };
    enum Enum2 { ENUM22 };
    histories.record("record", ENUM11, ENUM12, ENUM22);
    HistoryAssert::areEqual(histories.back(), "record", ENUM11, ENUM12, ENUM22);
}
}  // namespace History
}  // namespace AutoMacro
