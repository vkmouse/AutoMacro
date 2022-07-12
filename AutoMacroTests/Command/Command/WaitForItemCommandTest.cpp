#include "AutoMacro/Cv/Cv.h"
#include "AutoMacro/Command/Command.h"
#include "AutoMacro/Util/Util.h"
#include "AutoMacroTests/Command/CommandTest.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(WaitForItemCommandTest) {
int delayBetweenRepeatitions = 1;

public:
TEST_METHOD(TestWaitForItemExist) {
    Histories h;
    std::vector<std::string> f = {
        "images\\AutoMacroTests\\ItemNotExists_10x10_24bits.png",
        "images\\AutoMacroTests\\ItemNotExists_10x10_24bits.png",
        "images\\AutoMacroTests\\ItemExists_10x10_24bits.png" };
    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png" });

    WaitForItemCommandParameter p(getKvm(&h, f), detector, 0, 0.98f);
    p.delayBetweenRepeatitions = delayBetweenRepeatitions;
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

TEST_METHOD(TestWaitForItemDisappear) {
    Histories h;
    std::vector<std::string> f = {
        "images\\AutoMacroTests\\ItemExists_10x10_24bits.png",
        "images\\AutoMacroTests\\ItemExists_10x10_24bits.png",
        "images\\AutoMacroTests\\ItemNotExists_10x10_24bits.png" };
    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png" });

    WaitForItemCommandParameter p(getKvm(&h, f), detector, 0, 0.98f);
    p.delayBetweenRepeatitions = delayBetweenRepeatitions;
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
