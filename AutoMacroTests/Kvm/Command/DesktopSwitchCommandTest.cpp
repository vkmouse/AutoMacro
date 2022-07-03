#include "AutoMacro/Kvm/Kvm.h"
#include "AutoMacro/Util/Util.h"
#include "AutoMacroTests/Kvm/Command/CommandTest.h"
#include "CppUnitTest.h"

namespace AutoMacro {
namespace CommandTest {
using Microsoft::VisualStudio::CppUnitTestFramework::Assert;

TEST_CLASS(DesktopSwitchCommandTest) {
int delayBeforeCommand = 1;
int delayAfterCommand = 2;
int dBetweenEachSwitch = 3;

// Fix parameter in command
int delayBeforeShortcut = 0;
int delayAfterShortcut = 0;
int delayBetweenEachPressKey = 0;
int delayBetweenEachReleaseKey = 0;
int delayBetweenPressKeyAndReleaseKey = 1;

public:
TEST_METHOD_INITIALIZE(methodInitialize) {
    Histories h;
    DesktopSwitchCommandParameter p(getKvm(&h), 3, 1);
    p.delayBeforeCommand = delayBeforeCommand;
    p.delayAfterCommand = delayAfterCommand;
    p.delayBetweemEachSwitch = dBetweenEachSwitch;

    execute(&h, p);

    int i = 0;
    Assert::IsTrue(h[i++].equals("---"));
    Assert::IsTrue(h[i++].equals("delay", delayBeforeCommand));
    Assert::IsTrue(h[i++].equals("delay", delayBeforeShortcut));
    Assert::IsTrue(h[i++].equals("pressKey", KeyCode::KEY_LCTRL));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenEachPressKey));
    Assert::IsTrue(h[i++].equals("pressKey", KeyCode::KEY_LMETA));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenEachPressKey));
    Assert::IsTrue(h[i++].equals("pressKey", KeyCode::KEY_LEFT));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenPressKeyAndReleaseKey));
    Assert::IsTrue(h[i++].equals("releaseKey", KeyCode::KEY_LEFT));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenEachReleaseKey));
    Assert::IsTrue(h[i++].equals("releaseKey", KeyCode::KEY_LMETA));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenEachReleaseKey));
    Assert::IsTrue(h[i++].equals("releaseKey", KeyCode::KEY_LCTRL));
    Assert::IsTrue(h[i++].equals("delay", dBetweenEachSwitch));
    Assert::IsTrue(h[i++].equals("pressKey", KeyCode::KEY_LCTRL));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenEachPressKey));
    Assert::IsTrue(h[i++].equals("pressKey", KeyCode::KEY_LMETA));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenEachPressKey));
    Assert::IsTrue(h[i++].equals("pressKey", KeyCode::KEY_LEFT));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenPressKeyAndReleaseKey));
    Assert::IsTrue(h[i++].equals("releaseKey", KeyCode::KEY_LEFT));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenEachReleaseKey));
    Assert::IsTrue(h[i++].equals("releaseKey", KeyCode::KEY_LMETA));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenEachReleaseKey));
    Assert::IsTrue(h[i++].equals("releaseKey", KeyCode::KEY_LCTRL));
    Assert::IsTrue(h[i++].equals("delay", delayAfterShortcut));
    Assert::IsTrue(h[i++].equals("delay", delayAfterCommand));
    Assert::IsTrue(h[i++].equals("---"));
}

TEST_METHOD_CLEANUP(methodCleanup) {
    Histories h;
    DesktopSwitchCommandParameter p(getKvm(&h), 1, 1);
    p.delayBeforeCommand = delayBeforeCommand;
    p.delayAfterCommand = delayAfterCommand;

    execute(&h, p);

    int i = 0;
    Assert::IsTrue(h[i++].equals("---"));
    Assert::IsTrue(h[i++].equals("delay", delayBeforeCommand));
    Assert::IsTrue(h[i++].equals("delay", delayAfterCommand));
    Assert::IsTrue(h[i++].equals("---"));
}

TEST_METHOD(TestDesktopSwitch) {
    Histories h;
    DesktopSwitchCommandParameter p1(getKvm(&h), 3, 1);
    p1.delayBeforeCommand = delayBeforeCommand;
    p1.delayAfterCommand = delayAfterCommand;
    DesktopSwitchCommandParameter p2(getKvm(&h), 3, 2);
    p2.delayBeforeCommand = delayBeforeCommand;
    p2.delayAfterCommand = delayAfterCommand;

    execute(&h, p1, p2);

    int i = 0;
    Assert::IsTrue(h[i++].equals("---"));
    Assert::IsTrue(h[i++].equals("delay", delayBeforeCommand));
    Assert::IsTrue(h[i++].equals("delay", delayAfterCommand));
    Assert::IsTrue(h[i++].equals("---"));
    Assert::IsTrue(h[i++].equals("delay", delayBeforeCommand));
    Assert::IsTrue(h[i++].equals("delay", delayBeforeShortcut));
    Assert::IsTrue(h[i++].equals("pressKey", KeyCode::KEY_LCTRL));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenEachPressKey));
    Assert::IsTrue(h[i++].equals("pressKey", KeyCode::KEY_LMETA));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenEachPressKey));
    Assert::IsTrue(h[i++].equals("pressKey", KeyCode::KEY_RIGHT));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenPressKeyAndReleaseKey));
    Assert::IsTrue(h[i++].equals("releaseKey", KeyCode::KEY_RIGHT));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenEachReleaseKey));
    Assert::IsTrue(h[i++].equals("releaseKey", KeyCode::KEY_LMETA));
    Assert::IsTrue(h[i++].equals("delay", delayBetweenEachReleaseKey));
    Assert::IsTrue(h[i++].equals("releaseKey", KeyCode::KEY_LCTRL));
    Assert::IsTrue(h[i++].equals("delay", delayAfterShortcut));
    Assert::IsTrue(h[i++].equals("delay", delayAfterCommand));
    Assert::IsTrue(h[i++].equals("---"));
}
};
}  // namespace CommandTest
}  // namespace AutoMacro
