#include "AutoMacro/Cv/Cv.h"
#include "AutoMacro/Kvm/Kvm.h"
#include "AutoMacro/Util/Util.h"
#include "AutoMacroTests/Cv/Command/CommandTest.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(RequestItemExistsCommand) {
int delayBeforeCommand = 1;
int delayAfterCommand = 2;

public:
TEST_METHOD(TestExistedItem) {
    Histories h;
    std::vector<std::string> f = {
        "images\\AutoMacroTests\\ItemExists_10x10_24bits.png" };
    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png" });

    RequestItemExistsCommandParameter p(getKvm(&h, f), detector, 0, 0.98f);
    p.delayBeforeCommand = delayBeforeCommand;
    p.delayAfterCommand = delayAfterCommand;

    auto cmd = Factory::createTCommand(&p);
    h.record("---");
    bool isExisted = cmd->execute();
    h.record("---");

    int i = 0;
    Assert::IsTrue(h[i++].equals("---"));
    Assert::IsTrue(h[i++].equals("delay", delayBeforeCommand));
    Assert::IsTrue(h[i++].equals("takeSnapshot"));
    Assert::IsTrue(h[i++].equals("delay", delayAfterCommand));
    Assert::IsTrue(h[i++].equals("---"));
    Assert::IsTrue(isExisted);
}

TEST_METHOD(TestNotExistedItem) {
    Histories h;
    std::vector<std::string> f = {
        "images\\AutoMacroTests\\ItemNotExists_10x10_24bits.png" };
    auto detector = Factory::createTemplateBasedDetector({
        "images\\AutoMacroTests\\Template_5x5_24bits.png" });

    RequestItemExistsCommandParameter p(getKvm(&h, f), detector, 0, 0.98f);
    p.delayBeforeCommand = delayBeforeCommand;
    p.delayAfterCommand = delayAfterCommand;

    auto cmd = Factory::createTCommand(&p);
    h.record("---");
    bool isExisted = cmd->execute();
    h.record("---");

    int i = 0;
    Assert::IsTrue(h[i++].equals("---"));
    Assert::IsTrue(h[i++].equals("delay", delayBeforeCommand));
    Assert::IsTrue(h[i++].equals("takeSnapshot"));
    Assert::IsTrue(h[i++].equals("delay", delayAfterCommand));
    Assert::IsTrue(h[i++].equals("---"));
    Assert::IsFalse(isExisted);
}
};
}  // namespace CommandTest
}  // namespace AutoMacro
