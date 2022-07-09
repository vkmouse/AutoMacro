#include "AutoMacroTests/Cv/Command/CommandTest.h"

#include "AutoMacro/Cv/Cv.h"
#include "AutoMacro/Util/Util.h"

namespace AutoMacro {
namespace CommandTest {
Kvm getKvm(Histories* histories, std::vector<std::string> filenames) {
    Kvm kvm;
    kvm.delay = Factory::createMockDelay();
    kvm.keyboard = Factory::createMockKeyboard();
    kvm.mouse = Factory::createMockMouse();
    kvm.videoCapture = Factory::createImageFileCapture(filenames);

    kvm.delay = Util::addHistoryAgent(kvm.delay, histories);
    kvm.keyboard = Util::addHistoryAgent(kvm.keyboard, histories);
    kvm.mouse = Util::addHistoryAgent(kvm.mouse, histories);
    kvm.videoCapture = Util::addHistoryAgent(kvm.videoCapture, histories);

    return kvm;
}
}  // namespace CommandTest
}  // namespace AutoMacro
