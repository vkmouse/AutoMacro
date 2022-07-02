#include "AutoMacro/Cv/Cv.h"
#include "AutoMacro/Kvm/Kvm.h"
#include "AutoMacro/Util/Util.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(WaitForItemsCommandTest) {
public:
TEST_METHOD(TestWaitForAllItems) {
    Histories histories;
    auto videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTests\\ItemNotExists_10x10_24bits.png",
        "images\\AutoMacroTests\\ItemExists_10x10_24bits.png",
        "images\\AutoMacroTests\\AllItemExists_10x10_24bits.png" });
    auto delay = Factory::createMockDelay();
    videoCapture = Util::addHistoryAgent(videoCapture, &histories);
    delay = Util::addHistoryAgent(delay, &histories);

    auto detector1 = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png" });
    auto detector2 = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\BlackWithWhiteBorder_5x5_24bits.png" });

    int dBeforeCmd = 1;
    int dAfterCmd = 2;
    int dBetweenRp = 3;

    WaitForItemsCommandParameter p(nullptr, nullptr, videoCapture, delay,
        { detector1, detector2 },
        { 0, 0 },
        { 0.98f, 0.98f });

    p.delayBeforeCommand = dBeforeCmd;
    p.delayAfterCommand = dAfterCmd;
    p.delayBetweenRepeatitions = dBetweenRp;
    p.waitForExists = true;
    p.waitForAllItems = true;

    auto cmd = Factory::createCommand(&p);

    histories.record("---");
    cmd->execute();
    histories.record("---");

    int idx = 0;
    Assert::IsTrue(histories[idx++].equals("---"));
    Assert::IsTrue(histories[idx++].equals("delay", dBeforeCmd));
    Assert::IsTrue(histories[idx++].equals("takeSnapshot"));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenRp));
    Assert::IsTrue(histories[idx++].equals("takeSnapshot"));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenRp));
    Assert::IsTrue(histories[idx++].equals("takeSnapshot"));
    Assert::IsTrue(histories[idx++].equals("delay", dAfterCmd));
    Assert::IsTrue(histories[idx++].equals("---"));
}

TEST_METHOD(TestWaitForAtLeastOneItem) {
    Histories histories;
    auto videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTests\\ItemNotExists_10x10_24bits.png",
        "images\\AutoMacroTests\\ItemExists_10x10_24bits.png",
        "images\\AutoMacroTests\\AllItemExists_10x10_24bits.png" });
    auto delay = Factory::createMockDelay();
    videoCapture = Util::addHistoryAgent(videoCapture, &histories);
    delay = Util::addHistoryAgent(delay, &histories);

    auto detector1 = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png" });
    auto detector2 = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\BlackWithWhiteBorder_5x5_24bits.png" });

    int dBeforeCmd = 1;
    int dAfterCmd = 2;
    int dBetweenRp = 3;

    WaitForItemsCommandParameter p(nullptr, nullptr, videoCapture, delay,
        { detector1, detector2 },
        { 0, 0 },
        { 0.98f, 0.98f });

    p.delayBeforeCommand = dBeforeCmd;
    p.delayAfterCommand = dAfterCmd;
    p.delayBetweenRepeatitions = dBetweenRp;
    p.waitForExists = true;
    p.waitForAllItems = false;

    auto cmd = Factory::createCommand(&p);

    histories.record("---");
    cmd->execute();
    histories.record("---");
    cmd->execute();
    histories.record("---");

    int idx = 0;
    Assert::IsTrue(histories[idx++].equals("---"));
    Assert::IsTrue(histories[idx++].equals("delay", dBeforeCmd));
    Assert::IsTrue(histories[idx++].equals("takeSnapshot"));
    Assert::IsTrue(histories[idx++].equals("delay", dBetweenRp));
    Assert::IsTrue(histories[idx++].equals("takeSnapshot"));
    Assert::IsTrue(histories[idx++].equals("delay", dAfterCmd));
    Assert::IsTrue(histories[idx++].equals("---"));
    Assert::IsTrue(histories[idx++].equals("delay", dBeforeCmd));
    Assert::IsTrue(histories[idx++].equals("takeSnapshot"));
    Assert::IsTrue(histories[idx++].equals("delay", dAfterCmd));
    Assert::IsTrue(histories[idx++].equals("---"));
}
};
}  // namespace CommandTest
}  // namespace AutoMacro
