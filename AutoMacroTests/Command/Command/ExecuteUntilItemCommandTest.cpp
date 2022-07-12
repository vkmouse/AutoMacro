#include "AutoMacro/Cv/Cv.h"
#include "AutoMacro/Command/Command.h"
#include "AutoMacro/Util/Util.h"
#include "AutoMacroTests/Command/CommandTest.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(ExecuteUntilItemCommandTest) {
int delayBetweenRepeatitions = 1;

public:
TEST_METHOD(TestExecuteUntilItemExist) {
    Histories h;
    std::vector<std::string> f = {
        "images\\AutoMacroTests\\ItemNotExists_10x10_24bits.png",
        "images\\AutoMacroTests\\ItemNotExists_10x10_24bits.png",
        "images\\AutoMacroTests\\ItemExists_10x10_24bits.png" };
    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png" });

    DelayCommandParameter delayParameter(getKvm(&h, f));
    delayParameter.ms = delayBetweenRepeatitions;
    ExecuteUntilItemCommandParameter p(getKvm(&h, f), detector, 0, 0.98f,
        Factory::createCommand(&delayParameter));
    p.isExpectedToExist = true;

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

TEST_METHOD(TestExecuteUntilItemDisappear) {
    Histories h;
    std::vector<std::string> f = {
        "images\\AutoMacroTests\\ItemExists_10x10_24bits.png",
        "images\\AutoMacroTests\\ItemExists_10x10_24bits.png",
        "images\\AutoMacroTests\\ItemNotExists_10x10_24bits.png" };
    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png" });

    DelayCommandParameter delayParameter(getKvm(&h, f));
    delayParameter.ms = delayBetweenRepeatitions;
    ExecuteUntilItemCommandParameter p(getKvm(&h, f), detector, 0, 0.98f,
        Factory::createCommand(&delayParameter));
    p.isExpectedToExist = false;

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
};
}  // namespace CommandTest
}  // namespace AutoMacro
