#include "AutoMacro/Command/Command.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(CounterCommandTest) {
public:
TEST_METHOD(TestCreateCommand) {
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

TEST_METHOD(TestCreateTCommand) {
    int count = 0;
    CounterCommandParameter p(&count);
    auto cmd = Factory::createTCommand(&p);

    Assert::AreEqual(0, count);

    cmd->execute();
    Assert::AreEqual(1, count);

    cmd->execute();
    cmd->execute();
    Assert::AreEqual(3, count);
}
};
}  // namespace CommandTest
}  // namespace AutoMacro
