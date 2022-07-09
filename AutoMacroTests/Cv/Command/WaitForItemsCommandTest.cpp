#include "AutoMacro/Cv/Cv.h"
#include "AutoMacro/Util/Util.h"
#include "AutoMacroTests/Cv/Command/CommandTest.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(WaitForItemsCommandTest) {
int delayBeforeCommand = 1;
int delayAfterCommand = 2;
int delayBetweenRepeatitions = 3;

public:
TEST_METHOD(TestWaitForAllItems) {
    Histories h;
    std::vector<std::string> f = {
        "images\\AutoMacroTests\\ItemNotExists_10x10_24bits.png",
        "images\\AutoMacroTests\\ItemExists_10x10_24bits.png",
        "images\\AutoMacroTests\\AllItemExists_10x10_24bits.png" };
    auto detector1 = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png" });
    auto detector2 = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\BlackWithWhiteBorder_5x5_24bits.png" });

    WaitForItemsCommandParameter p(getKvm(&h, f),
        { detector1, detector2 },
        { 0, 0 },
        { 0.98f, 0.98f });
    p.delayBeforeCommand = delayBeforeCommand;
    p.delayAfterCommand = delayAfterCommand;
    p.delayBetweenRepeatitions = delayBetweenRepeatitions;
    p.waitForExists = true;
    p.waitForAllItems = true;

    execute(&h, p);

    int i = 0;
    Assert::IsTrue(h[i++].equals("---"));
    Assert::IsTrue(h[i++].equals("delay", delayBeforeCommand));
    Assert::IsTrue(h[i++].equals("takeSnapshot"));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenRepeatitions));
    Assert::IsTrue(h[i++].equals("takeSnapshot"));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenRepeatitions));
    Assert::IsTrue(h[i++].equals("takeSnapshot"));
    Assert::IsTrue(h[i++].equals("delay", delayAfterCommand));
    Assert::IsTrue(h[i++].equals("---"));
}

TEST_METHOD(TestWaitForAtLeastOneItem) {
    Histories h;
    std::vector<std::string> f = {
        "images\\AutoMacroTests\\ItemNotExists_10x10_24bits.png",
        "images\\AutoMacroTests\\ItemExists_10x10_24bits.png",
        "images\\AutoMacroTests\\AllItemExists_10x10_24bits.png" };
    auto detector1 = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png" });
    auto detector2 = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\BlackWithWhiteBorder_5x5_24bits.png" });

    WaitForItemsCommandParameter p(getKvm(&h, f),
        { detector1, detector2 },
        { 0, 0 },
        { 0.98f, 0.98f });
    p.delayBeforeCommand = delayBeforeCommand;
    p.delayAfterCommand = delayAfterCommand;
    p.delayBetweenRepeatitions = delayBetweenRepeatitions;
    p.waitForExists = true;
    p.waitForAllItems = false;

    execute(&h, p, p);

    int i = 0;
    Assert::IsTrue(h[i++].equals("---"));
    Assert::IsTrue(h[i++].equals("delay", delayBeforeCommand));
    Assert::IsTrue(h[i++].equals("takeSnapshot"));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenRepeatitions));
    Assert::IsTrue(h[i++].equals("takeSnapshot"));
    Assert::IsTrue(h[i++].equals("delay", delayAfterCommand));
    Assert::IsTrue(h[i++].equals("---"));
    Assert::IsTrue(h[i++].equals("delay", delayBeforeCommand));
    Assert::IsTrue(h[i++].equals("takeSnapshot"));
    Assert::IsTrue(h[i++].equals("delay", delayAfterCommand));
    Assert::IsTrue(h[i++].equals("---"));
}
};
}  // namespace CommandTest
}  // namespace AutoMacro
