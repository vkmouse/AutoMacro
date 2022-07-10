#include "AutoMacro/Command/Command.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(EmptyCommandTest) {
public:
TEST_METHOD(TestEmptyCommand) {
    auto cmd = Factory::createCommand();
    cmd->execute();
}

TEST_METHOD(TestEmptyVoidCommand) {
    auto cmd = Factory::createTCommand<void>();
    cmd->execute();
}

TEST_METHOD(TestEmptyBoolCommand) {
    auto cmd = Factory::createTCommand<bool>();
    bool output = cmd->execute();
    Assert::IsFalse(output);
}
};
}  // namespace CommandTest
}  // namespace AutoMacro
