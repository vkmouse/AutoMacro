#include "AutoMacro/Kvm/Kvm/ActualDelay.h"

#include <thread>
#include <chrono>

namespace AutoMacro {
namespace Impl {
void ActualDelay::execute(int ms) {
    using std::chrono::high_resolution_clock;

    auto start = high_resolution_clock::now();
    auto timeout = std::chrono::milliseconds(ms);
    auto tinyDelay = std::chrono::milliseconds(14);

    if (timeout > tinyDelay) {
        std::this_thread::sleep_for(timeout - tinyDelay);
    }

    auto duration = [&start]() { return high_resolution_clock::now() - start; };
    while (duration() < timeout) {}
}
}  // namespace Impl
}  // namespace AutoMacro
