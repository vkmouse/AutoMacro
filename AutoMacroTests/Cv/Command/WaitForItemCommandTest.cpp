#include "AutoMacro/Cv/Cv.h"
#include "AutoMacro/Kvm/Kvm.h"
#include "AutoMacro/Util/Util.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(WaitForItemCommandTest) {
public:
TEST_METHOD(TestWaitForItemExist) {
    Histories histories;
    auto videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTests\\ItemNotExists_10x10_24bits.png",
        "images\\AutoMacroTests\\ItemNotExists_10x10_24bits.png",
        "images\\AutoMacroTests\\ItemExists_10x10_24bits.png" });
    auto delay = Factory::createMockDelay();
    videoCapture = Util::addHistoryAgent(videoCapture, &histories);
    delay = Util::addHistoryAgent(delay, &histories);

    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png" });

    int dBeforeCmd = 1;
    int dAfterCmd = 2;
    int dBetweenRp = 3;

    WaitForItemCommandParameter p(nullptr, nullptr, videoCapture, delay,
        detector, 0, 0.98f);
    p.delayBeforeCommand = dBeforeCmd;
    p.delayAfterCommand = dAfterCmd;
    p.delayBetweenRepeatitions = dBetweenRp;
    p.waitForExists = true;

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

TEST_METHOD(TestWaitForItemNotExist) {
    Histories histories;
    auto videoCapture = Factory::createImageFileCapture({
        "images\\AutoMacroTests\\ItemExists_10x10_24bits.png",
        "images\\AutoMacroTests\\ItemExists_10x10_24bits.png",
        "images\\AutoMacroTests\\ItemNotExists_10x10_24bits.png" });
    auto delay = Factory::createMockDelay();
    videoCapture = Util::addHistoryAgent(videoCapture, &histories);
    delay = Util::addHistoryAgent(delay, &histories);

    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png" });

    int dBeforeCmd = 1;
    int dAfterCmd = 2;
    int dBetweenRp = 3;

    WaitForItemCommandParameter p(nullptr, nullptr, videoCapture, delay,
        detector, 0, 0.98f);
    p.delayBeforeCommand = dBeforeCmd;
    p.delayAfterCommand = dAfterCmd;
    p.delayBetweenRepeatitions = dBetweenRp;
    p.waitForExists = false;

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
};
}  // namespace CommandTest
}  // namespace AutoMacro
