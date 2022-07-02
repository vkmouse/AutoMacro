#include "AutoMacro/Kvm/Kvm.h"
#include "AutoMacro/Util/Util.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace HistoryTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(DelayHistoryAgentTest) {
public:
TEST_METHOD(TestDelayHistoryAgent) {
    Histories histories;
    auto delay = Factory::createMockDelay();
    delay = Util::addHistoryAgent(delay, &histories);

    delay->execute(421);
    Assert::IsTrue(histories.back().equals("delay", 421));

    delay->execute(253);
    Assert::IsTrue(histories.back().equals("delay", 253));
}
};
}  // namespace HistoryTest
}  // namespace AutoMacro
