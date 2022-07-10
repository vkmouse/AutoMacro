#include "AutoMacro/Cv/Cv.h"
#include "AutoMacro/Command/Command.h"
#include "AutoMacro/Util/Util.h"
#include "AutoMacroTests/Command/CommandTest.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(CheckItemExistenceCommandTest) {
int delayBeforeCommand = 1;
int delayAfterCommand = 2;

void testMethod(std::string filename,
                bool isExpectedToExist,
                bool expectedIsCorrect) {
    Histories h;
    std::vector<std::string> f = { filename };
    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png" });

    CheckItemExistenceCommandParameter p(getKvm(&h, f),
                                         detector, 0, 0.98f);
    p.isExpectedToExist = isExpectedToExist;
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
    auto filename = "images\\AutoMacroTests\\ItemExists_10x10_24bits.png";
    bool isExpectedToExist = true;
    bool expectedIsCorrect = true;
    testMethod(filename, isExpectedToExist, expectedIsCorrect);
}

TEST_METHOD(TestFalsePositive) {
    auto filename = "images\\AutoMacroTests\\ItemExists_10x10_24bits.png";
    bool isExpectedToExist = false;
    bool expectedIsCorrect = false;
    testMethod(filename, isExpectedToExist, expectedIsCorrect);
}

TEST_METHOD(TestTrueNegative) {
    auto filename = "images\\AutoMacroTests\\ItemNotExists_10x10_24bits.png";
    bool isExpectedToExist = false;
    bool expectedIsCorrect = true;
    testMethod(filename, isExpectedToExist, expectedIsCorrect);
}

TEST_METHOD(TestFalseNegative) {
    auto filename = "images\\AutoMacroTests\\ItemNotExists_10x10_24bits.png";
    bool isExpectedToExist = true;
    bool expectedIsCorrect = false;
    testMethod(filename, isExpectedToExist, expectedIsCorrect);
}
};
}  // namespace CommandTest
}  // namespace AutoMacro
