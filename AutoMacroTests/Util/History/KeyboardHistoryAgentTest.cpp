#include "AutoMacro/Kvm/Kvm.h"
#include "AutoMacro/Util/Util.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace HistoryTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(KeyboardHistoryAgentTest) {
public:
TEST_METHOD(TestKeyboardHistoryAgent) {
    Histories histories;
    auto keyboard = Factory::createMockKeyboard();
    keyboard = Util::addHistoryAgent(keyboard, &histories);

    keyboard->pressKey(KeyCode::KEY_A);
    Assert::IsTrue(histories.back().equals("pressKey", KeyCode::KEY_A));

    keyboard->releaseKey(KeyCode::KEY_B);
    Assert::IsTrue(histories.back().equals("releaseKey", KeyCode::KEY_B));

    keyboard->releaseAllKeys();
    Assert::IsTrue(histories.back().equals("releaseAllKeys"));
}
};
}  // namespace HistoryTest
}  // namespace AutoMacro
