#include "AutoMacro/Command/Command.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(ArithmeticOperationCommandTest) {
public:
TEST_METHOD(TestAddOperation) {
    int lhs = 10;
    ArithmeticOperationCommandParameter p(
        &lhs, 10, ArithmeticOperator::ADD);
    Factory::createTCommand(&p)->execute();
    Assert::AreEqual(20, lhs);
}

TEST_METHOD(TestSubtractOperation) {
    int lhs = 10;
    ArithmeticOperationCommandParameter p(
        &lhs, 5, ArithmeticOperator::SUBTRACT);
    Factory::createTCommand(&p)->execute();
    Assert::AreEqual(5, lhs);
}

TEST_METHOD(TestMultiplyOperation) {
    int lhs = 10;
    ArithmeticOperationCommandParameter p(
        &lhs, 5, ArithmeticOperator::MULTIPLY);
    Factory::createTCommand(&p)->execute();
    Assert::AreEqual(50, lhs);
}

TEST_METHOD(TestDivideOperation) {
    int lhs = 10;
    ArithmeticOperationCommandParameter p(
        &lhs, 5, ArithmeticOperator::DIVIDE);
    Factory::createTCommand(&p)->execute();
    Assert::AreEqual(2, lhs);
}
};
}  // namespace CommandTest
}  // namespace AutoMacro
