#include <memory>
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CoreTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(CommandsTest) {
public:
TEST_METHOD(TestMultipleCounter) {
    Kvm kvm;
    int count = 0;
    kvm.delay = Factory::createMockDelay();

    CounterCommandParameter counterParam(&count);
    std::vector<std::shared_ptr<Command>> cmds = {
        Factory::createCommand(&counterParam),
        Factory::createCommand(&counterParam),
        Factory::createCommand(&counterParam)
    };

    auto cmd = Factory::createCommand(&CommandsParameter(cmds));
    cmd->execute();
    Assert::AreEqual(3, count);

    cmds = { Factory::createCommand(&counterParam) };
    cmd = Factory::createCommand(&CommandsParameter(cmds));
    cmd->execute();
    Assert::AreEqual(4, count);
}
};
}  // namespace CoreTest
}  // namespace AutoMacro
