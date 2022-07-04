#include "AutoMacro/Core/Core.h"
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

    CounterCommandParameter p(&count);
    auto cmd = Factory::createCommand(&p);

    Assert::AreEqual(0, count);

    cmd->execute();
    Assert::AreEqual(1, count);

    cmd->execute();
    cmd->execute();
    Assert::AreEqual(3, count);
}

TEST_METHOD(TestEmptyCommand) {
    auto emptyCmd = Factory::createCommand();
    emptyCmd->execute();
}
};
}  // namespace CoreTest
}  // namespace AutoMacro
