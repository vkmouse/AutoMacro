#include "AutoMacro/Kvm/Kvm.h"
#include "AutoMacro/Util/Util.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace HistoryTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(VideoCaptureHistoryAgentTest) {
public:
TEST_METHOD(TestVideoCaptureHistoryAgent) {
    Histories histories;
    auto videoCapture = Factory::createMockVideoCapture();
    videoCapture = Util::addHistoryAgent(videoCapture, &histories);

    videoCapture->takeSnapshot();
    Assert::IsTrue(histories.back().equals("takeSnapshot"));
}
};
}  // namespace HistoryTest
}  // namespace AutoMacro
