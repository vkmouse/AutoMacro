#pragma once
#include <chrono>
#include <string>
#include <vector>

#include "AutoMacro/Core/pch.h"
#include "AutoMacro/History/History/History.h"

namespace AutoMacro {
namespace History {
class Histories : public std::vector<History> {
 public:
    DLL_EXPORTS void record(std::string message);

    template <typename T>
    DLL_EXPORTS void record(std::string message, T first);

    template <typename T, typename ...Ts>
    DLL_EXPORTS void record(std::string message, T first, Ts... rest);

    DLL_EXPORTS bool allDurationsAreInRange(
        std::vector<int> expectedTimes, int tolerence) const;

 private:
    DLL_EXPORTS void record(std::string message, std::vector<void*> parameters);

    std::vector<void*> pointers_;
};

template<typename T>
inline void Histories::record(std::string message, T first) {
    pointers_.push_back(malloc(sizeof(T)));
    memcpy(pointers_.back(), &first, sizeof(T));
    record(message, pointers_);
    pointers_.clear();
}

template<typename T, typename ...Ts>
inline void Histories::record(std::string message, T first, Ts ...rest) {
    pointers_.push_back(malloc(sizeof(T)));
    memcpy(pointers_.back(), &first, sizeof(T));
    record(message, rest...);
}
}  // namespace History
}  // namespace AutoMacro
