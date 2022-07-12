#include "AutoMacro/Command/Command.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(LogicalOperationCommandTest) {
int lhs = 10;
public:
TEST_METHOD(TestAndOperation) {
    ComparisonOperationCommandParameter cp1(lhs, 10, ComparisonOperator::EQUAL);
    ComparisonOperationCommandParameter cp2(lhs, 11, ComparisonOperator::EQUAL);
    auto trueCmd = Factory::createTCommand(&cp1);
    auto falseCmd = Factory::createTCommand(&cp2);

    LogicalOperationCommandParameter p1(
        { trueCmd, trueCmd }, LogicalOperator::AND);
    auto output = Factory::createTCommand(&p1)->execute();
    Assert::IsTrue(output);

    LogicalOperationCommandParameter p2(
        { trueCmd, falseCmd }, LogicalOperator::AND);
    output = Factory::createTCommand(&p2)->execute();
    Assert::IsFalse(output);

    LogicalOperationCommandParameter p3(
        { falseCmd, falseCmd }, LogicalOperator::AND);
    output = Factory::createTCommand(&p3)->execute();
    Assert::IsFalse(output);
}

TEST_METHOD(TestOrOperation) {
    ComparisonOperationCommandParameter cp1(lhs, 10, ComparisonOperator::EQUAL);
    ComparisonOperationCommandParameter cp2(lhs, 11, ComparisonOperator::EQUAL);
    auto trueCmd = Factory::createTCommand(&cp1);
    auto falseCmd = Factory::createTCommand(&cp2);

    LogicalOperationCommandParameter p1(
        { trueCmd, trueCmd }, LogicalOperator::OR);
    auto output = Factory::createTCommand(&p1)->execute();
    Assert::IsTrue(output);

    LogicalOperationCommandParameter p2(
        { trueCmd, falseCmd }, LogicalOperator::OR);
    output = Factory::createTCommand(&p2)->execute();
    Assert::IsTrue(output);

    LogicalOperationCommandParameter p3(
        { falseCmd, falseCmd }, LogicalOperator::OR);
    output = Factory::createTCommand(&p3)->execute();
    Assert::IsFalse(output);
}

TEST_METHOD(TestXorOperation) {
    ComparisonOperationCommandParameter cp1(lhs, 10, ComparisonOperator::EQUAL);
    ComparisonOperationCommandParameter cp2(lhs, 11, ComparisonOperator::EQUAL);
    auto trueCmd = Factory::createTCommand(&cp1);
    auto falseCmd = Factory::createTCommand(&cp2);

    LogicalOperationCommandParameter p1(
        { trueCmd, trueCmd }, LogicalOperator::XOR);
    auto output = Factory::createTCommand(&p1)->execute();
    Assert::IsFalse(output);

    LogicalOperationCommandParameter p2(
        { trueCmd, falseCmd }, LogicalOperator::XOR);
    output = Factory::createTCommand(&p2)->execute();
    Assert::IsTrue(output);

    LogicalOperationCommandParameter p3(
        { falseCmd, falseCmd }, LogicalOperator::XOR);
    output = Factory::createTCommand(&p3)->execute();
    Assert::IsFalse(output);
}

TEST_METHOD(TestValues) {
    ComparisonOperationCommandParameter cp1(lhs, 10, ComparisonOperator::EQUAL);
    ComparisonOperationCommandParameter cp2(lhs, 11, ComparisonOperator::EQUAL);
    auto trueCmd = Factory::createTCommand(&cp1);
    auto falseCmd = Factory::createTCommand(&cp2);

    LogicalOperationCommandParameter p1(
        trueCmd, false, LogicalOperator::AND);
    auto output = Factory::createTCommand(&p1)->execute();
    Assert::IsFalse(output);

    LogicalOperationCommandParameter p2(
        trueCmd, true, LogicalOperator::AND);
    output = Factory::createTCommand(&p2)->execute();
    Assert::IsTrue(output);

    LogicalOperationCommandParameter p3(
        falseCmd, true, LogicalOperator::AND);
    output = Factory::createTCommand(&p3)->execute();
    Assert::IsFalse(output);
}
};
}  // namespace CommandTest
}  // namespace AutoMacro
