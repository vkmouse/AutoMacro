#include "AutoMacro/Core/Core.h"
#include "AutoMacroTests/Core/Core/CounterCommand.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CoreTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(CommandTest) {
public:
TEST_METHOD(TestCounterCommand) {
    Kvm kvm;
    kvm.delay = Factory::createMockDelay();
    int count = 0;

    CounterCommandParameter p(kvm, &count);
    CounterCommand cmd(&p);

    Assert::AreEqual(0, count);

    cmd.execute();
    Assert::AreEqual(1, count);

    cmd.execute();
    cmd.execute();
    Assert::AreEqual(3, count);
}
};
}  // namespace CoreTest
}  // namespace AutoMacro
