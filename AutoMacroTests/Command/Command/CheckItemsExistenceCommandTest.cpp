#include "AutoMacro/Cv/Cv.h"
#include "AutoMacro/Command/Command.h"
#include "AutoMacro/Util/Util.h"
#include "AutoMacroTests/Command/CommandTest.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(CheckItemsExistenceCommandTest) {
int delayBeforeCommand = 1;
int delayAfterCommand = 2;

void testMethod(std::string filename,
                bool isExpectedToAllExist,
                bool expectedIsCorrect) {
    Histories h;
    std::vector<std::string> f = { filename };
    auto detector1 = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png" });
    auto detector2 = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\BlackWithWhiteBorder_5x5_24bits.png" });

    CheckItemsExistenceCommandParameter p(getKvm(&h, f),
        { detector1, detector2 },
        { 0, 0 },
        { 0.98f, 0.98f });
    p.isExpectedToExist = true;
    p.isExpectedToAllExist = isExpectedToAllExist;
    p.delayBeforeCommand = delayBeforeCommand;
    p.delayAfterCommand = delayAfterCommand;

    auto cmd = Factory::createTCommand(&p);
    h.record("---");
    bool actualIsCorrect = cmd->execute();
    h.record("---");

    int i = 0;
    Assert::IsTrue(h[i++].equals("---"));
    Assert::IsTrue(h[i++].equals("delay", delayBeforeCommand));
    Assert::IsTrue(h[i++].equals("takeSnapshot"));
    Assert::IsTrue(h[i++].equals("delay", delayAfterCommand));
    Assert::IsTrue(h[i++].equals("---"));
    Assert::AreEqual(expectedIsCorrect, actualIsCorrect);
}

public:
TEST_METHOD(TestTruePositive) {
    auto filename = "images\\AutoMacroTests\\AllItemExists_10x10_24bits.png";
    bool isExpectedToAllExist = true;
    bool expectedIsCorrect = true;
    testMethod(filename, isExpectedToAllExist, expectedIsCorrect);
}

TEST_METHOD(TestFalsePositive) {
    auto filename = "images\\AutoMacroTests\\ItemExists_10x10_24bits.png";
    bool isExpectedToAllExist = true;
    bool expectedIsCorrect = false;
    testMethod(filename, isExpectedToAllExist, expectedIsCorrect);
}

TEST_METHOD(TestTrueNegative) {
    auto filename = "images\\AutoMacroTests\\ItemExists_10x10_24bits.png";
    bool isExpectedToAllExist = false;
    bool expectedIsCorrect = true;
    testMethod(filename, isExpectedToAllExist, expectedIsCorrect);
}

TEST_METHOD(TestFalseNegative) {
    auto filename = "images\\AutoMacroTests\\ItemNotExists_10x10_24bits.png";
    bool isExpectedToAllExist = true;
    bool expectedIsCorrect = false;
    testMethod(filename, isExpectedToAllExist, expectedIsCorrect);
}
};
}  // namespace CommandTest
}  // namespace AutoMacro
