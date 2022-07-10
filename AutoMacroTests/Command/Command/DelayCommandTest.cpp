#include "AutoMacro/Command/Command.h"
#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Util/Util.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(DelayCommandTest) {
public:
TEST_METHOD(TestDelayCommand) {
    Histories h;
    Kvm kvm;
    kvm.delay = Factory::createMockDelay();
    kvm.delay = Util::addHistoryAgent(kvm.delay, &h);
    DelayCommandParameter p(kvm);
    p.ms = 100;
    auto cmd = Factory::createCommand(&p);

    h.record("---");
    cmd->execute();
    h.record("---");

    int i = 0;
    Assert::IsTrue(h[i++].equals("---"));
    Assert::IsTrue(h[i++].equals("delay", 0));
    Assert::IsTrue(h[i++].equals("delay", p.ms));
    Assert::IsTrue(h[i++].equals("delay", 0));
    Assert::IsTrue(h[i++].equals("---"));
}
};
}  // namespace CommandTest
}  // namespace AutoMacro
