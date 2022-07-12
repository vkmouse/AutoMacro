#include "AutoMacro/Cv/Cv.h"
#include "AutoMacro/Command/Command.h"
#include "AutoMacro/Util/Util.h"
#include "AutoMacroTests/Command/CommandTest.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(ExecuteUntilItemsCommandTest) {
int delayBeforeCommand = 1;
int delayAfterCommand = 2;
int delayBetweenRepeatitions = 3;

public:
TEST_METHOD(TestExecuteUntilAllItemsAppear) {
    Histories h;
    std::vector<std::string> f = {
        "images\\AutoMacroTests\\ItemNotExists_10x10_24bits.png",
        "images\\AutoMacroTests\\ItemExists_10x10_24bits.png",
        "images\\AutoMacroTests\\AllItemExists_10x10_24bits.png" };
    auto detector1 = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png" });
    auto detector2 = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\BlackWithWhiteBorder_5x5_24bits.png" });

    DelayCommandParameter delayParameter(getKvm(&h, f));
    delayParameter.ms = delayBetweenRepeatitions;
    ExecuteUntilItemsCommandParameter p(getKvm(&h, f),
        { detector1, detector2 },
        { 0, 0 },
        { 0.98f, 0.98f },
        Factory::createCommand(&delayParameter));
    p.isExpectedToExist = true;
    p.isExpectedToAllExist = true;

    execute(&h, p);

    int i = 0;
    Assert::IsTrue(h[i++].equals("---"));
    Assert::IsTrue(h[i++].equals("delay", 0));
    Assert::IsTrue(h[i++].equals("takeSnapshot"));
    Assert::IsTrue(h[i++].equals("delay", 0));
    Assert::IsTrue(h[i++].equals("delay", 0));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenRepeatitions));
    Assert::IsTrue(h[i++].equals("delay", 0));
    Assert::IsTrue(h[i++].equals("delay", 0));
    Assert::IsTrue(h[i++].equals("takeSnapshot"));
    Assert::IsTrue(h[i++].equals("delay", 0));
    Assert::IsTrue(h[i++].equals("delay", 0));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenRepeatitions));
    Assert::IsTrue(h[i++].equals("delay", 0));
    Assert::IsTrue(h[i++].equals("delay", 0));
    Assert::IsTrue(h[i++].equals("takeSnapshot"));
    Assert::IsTrue(h[i++].equals("delay", 0));
    Assert::IsTrue(h[i++].equals("---"));
}

TEST_METHOD(TestExecuteUntilAtLeastOneItem) {
    Histories h;
    std::vector<std::string> f = {
        "images\\AutoMacroTests\\ItemNotExists_10x10_24bits.png",
        "images\\AutoMacroTests\\ItemExists_10x10_24bits.png",
        "images\\AutoMacroTests\\AllItemExists_10x10_24bits.png" };
    auto detector1 = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png" });
    auto detector2 = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\BlackWithWhiteBorder_5x5_24bits.png" });

    DelayCommandParameter delayParameter(getKvm(&h, f));
    delayParameter.ms = delayBetweenRepeatitions;
    ExecuteUntilItemsCommandParameter p(getKvm(&h, f),
        { detector1, detector2 },
        { 0, 0 },
        { 0.98f, 0.98f },
        Factory::createCommand(&delayParameter));
    p.isExpectedToExist = true;
    p.isExpectedToAllExist = false;

    execute(&h, p, p);

    int i = 0;
    Assert::IsTrue(h[i++].equals("---"));
    Assert::IsTrue(h[i++].equals("delay", 0));
    Assert::IsTrue(h[i++].equals("takeSnapshot"));
    Assert::IsTrue(h[i++].equals("delay", 0));
    Assert::IsTrue(h[i++].equals("delay", 0));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenRepeatitions));
    Assert::IsTrue(h[i++].equals("delay", 0));
    Assert::IsTrue(h[i++].equals("delay", 0));
    Assert::IsTrue(h[i++].equals("takeSnapshot"));
    Assert::IsTrue(h[i++].equals("delay", 0));
    Assert::IsTrue(h[i++].equals("---"));
    Assert::IsTrue(h[i++].equals("delay", 0));
    Assert::IsTrue(h[i++].equals("takeSnapshot"));
    Assert::IsTrue(h[i++].equals("delay", 0));
    Assert::IsTrue(h[i++].equals("---"));
}
};
}  // namespace CommandTest
}  // namespace AutoMacro
