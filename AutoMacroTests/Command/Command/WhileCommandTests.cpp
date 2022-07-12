#include "AutoMacro/Cv/Cv.h"
#include "AutoMacro/Command/Command.h"
#include "AutoMacroTests/Command/CommandTest.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(WhileCommandTest) {
public:
TEST_METHOD(TestWhileCommand) {
    int count = 0;
    CounterCommandParameter cp(&count);
    ComparisonOperationCommandParameter cop(
        count, 10, ComparisonOperator::LESS_THAN);
    WhileCommandParameter p(
        Factory::createCommand(&cp), Factory::createTCommand(&cop));
    auto cmd = Factory::createCommand(&p);
    cmd->execute();
    Assert::AreEqual(10, count);
}
};
}  // namespace CommandTest
}  // namespace AutoMacro
