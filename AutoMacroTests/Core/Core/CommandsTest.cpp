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
    int count;
    kvm.delay = Factory::createMockDelay();

    std::vector<std::shared_ptr<Command>> cmds;
    CommandsParameter p(cmds);
    auto cmd = Factory::createCommand(&p);

    count = 0;
    CounterCommandParameter counterParam(&count);
    cmds.push_back(Factory::createCommand(&counterParam));
    cmd->execute();
    Assert::AreEqual(1, count);

    count = 0;
    cmds.clear();
    cmds.push_back(Factory::createCommand(&counterParam));
    cmds.push_back(Factory::createCommand(&counterParam));
    cmd->execute();
    Assert::AreEqual(2, count);

    cmd->execute();
    Assert::AreEqual(4, count);
}
};
}  // namespace CoreTest
}  // namespace AutoMacro
