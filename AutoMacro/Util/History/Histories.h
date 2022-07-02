#pragma once
#include <chrono>
#include <string>
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Util/History/History.h"

namespace AutoMacro {
class Histories : public std::vector<History> {
 public:
    DLL_EXPORTS void record(std::string message);

    template <typename T>
    DLL_EXPORTS void record(std::string message, T first);

    template <typename T, typename ...Ts>
    DLL_EXPORTS void record(std::string message, T first, Ts... rest);

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
}  // namespace AutoMacro
