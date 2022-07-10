#include <vector>

#include "AutoMacro/Command/Command.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(CommandsTest) {
public:
TEST_METHOD(TestMultipleCounter) {
    int count = 0;
    CounterCommandParameter counterParam(&count);
    std::vector<std::shared_ptr<Command>> cmds = {
        Factory::createCommand(&counterParam),
        Factory::createCommand(&counterParam),
        Factory::createCommand(&counterParam)
    };

    auto cmd = Factory::createCommand(cmds);
    cmd->execute();
    Assert::AreEqual(3, count);

    cmds = { Factory::createCommand(&counterParam) };
    cmd = Factory::createCommand(cmds);
    cmd->execute();
    Assert::AreEqual(4, count);
}
};
}  // namespace CommandTest
}  // namespace AutoMacro
