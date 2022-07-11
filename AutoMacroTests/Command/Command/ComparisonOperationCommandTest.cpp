#include "AutoMacro/Command/Command.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(ComparisonOperationCommandTest) {
int lhs = 10;
public:
TEST_METHOD(TestEqualComparison) {
    ComparisonOperationCommandParameter p(
        lhs, 10, ComparisonOperator::EQUAL);
    bool output = Factory::createTCommand(&p)->execute();
    Assert::IsTrue(output);

    p.rhs = 11;
    output = Factory::createTCommand(&p)->execute();
    Assert::IsFalse(output);
}

TEST_METHOD(TestGreaterThanComparison) {
    ComparisonOperationCommandParameter p(
        lhs, 9, ComparisonOperator::GREATER_THAN);
    bool output = Factory::createTCommand(&p)->execute();
    Assert::IsTrue(output);

    p.rhs = 10;
    output = Factory::createTCommand(&p)->execute();
    Assert::IsFalse(output);

    p.rhs = 11;
    output = Factory::createTCommand(&p)->execute();
    Assert::IsFalse(output);
}

TEST_METHOD(TestGreaterThanOrEqualComparison) {
    ComparisonOperationCommandParameter p(
        lhs, 9, ComparisonOperator::GREATER_THAN_OR_EQUAL);
    bool output = Factory::createTCommand(&p)->execute();
    Assert::IsTrue(output);

    p.rhs = 10;
    output = Factory::createTCommand(&p)->execute();
    Assert::IsTrue(output);

    p.rhs = 11;
    output = Factory::createTCommand(&p)->execute();
    Assert::IsFalse(output);
}

TEST_METHOD(TestLessThanComparison) {
    ComparisonOperationCommandParameter p(
        lhs, 11, ComparisonOperator::LESS_THAN);
    bool output = Factory::createTCommand(&p)->execute();
    Assert::IsTrue(output);

    p.rhs = 10;
    output = Factory::createTCommand(&p)->execute();
    Assert::IsFalse(output);

    p.rhs = 9;
    output = Factory::createTCommand(&p)->execute();
    Assert::IsFalse(output);
}

TEST_METHOD(TestLessThanOrEqualComparison) {
    ComparisonOperationCommandParameter p(
        lhs, 11, ComparisonOperator::LESS_THAN_OR_EQUAL);
    bool output = Factory::createTCommand(&p)->execute();
    Assert::IsTrue(output);

    p.rhs = 10;
    output = Factory::createTCommand(&p)->execute();
    Assert::IsTrue(output);

    p.rhs = 9;
    output = Factory::createTCommand(&p)->execute();
    Assert::IsFalse(output);
}

TEST_METHOD(TestNotEqualComparison) {
    ComparisonOperationCommandParameter p(
        lhs, 9, ComparisonOperator::NOT_EQUAL);
    bool output = Factory::createTCommand(&p)->execute();
    Assert::IsTrue(output);

    p.rhs = 10;
    output = Factory::createTCommand(&p)->execute();
    Assert::IsFalse(output);

    p.rhs = 11;
    output = Factory::createTCommand(&p)->execute();
    Assert::IsTrue(output);
}
};
}  // namespace CommandTest
}  // namespace AutoMacro
