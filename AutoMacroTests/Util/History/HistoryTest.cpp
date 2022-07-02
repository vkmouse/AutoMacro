#include "AutoMacro/Kvm/Kvm.h"
#include "AutoMacro/Util/Util.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace HistoryTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(HistoryTest) {
public:
TEST_METHOD(TestHistories) {
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
};
}  // namespace HistoryTest
}  // namespace AutoMacro
