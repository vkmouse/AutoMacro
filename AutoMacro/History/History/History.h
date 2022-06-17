#pragma once
#include <chrono>
#include <string>
#include <vector>

namespace AutoMacro {
namespace History {
struct History {
    std::chrono::steady_clock::time_point time;
    std::string message;
    std::vector<void*> pointers;
};
}  // namespace History
}  // namespace AutoMacro
