#pragma once
#include "AutoMacro/Kvm/Kvm.h"
#include "AutoMacro/Util/Util.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace KvmTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(ActualDelayTest) {
public:
TEST_METHOD(TestTinyDelay) {
    Histories histories;
    auto delay = Factory::createActualDelay();
    delay = Util::addHistoryAgent(delay, &histories);

    int expected = 100;
    histories.clear();
    histories.record("---");
    delay->execute(expected);
    int actual = Util::calcDuration(histories[0], histories[1]);
    Assert::AreEqual(expected, actual);

    expected = 10;
    histories.clear();
    histories.record("---");
    delay->execute(expected);
    actual = Util::calcDuration(histories[0], histories[1]);
    Assert::AreEqual(expected, actual);

    expected = 1;
    histories.clear();
    histories.record("---");
    delay->execute(expected);
    actual = Util::calcDuration(histories[0], histories[1]);
    Assert::AreEqual(expected, actual);
}
};
}  // namespace KvmTest
}  // namespace AutoMacro
