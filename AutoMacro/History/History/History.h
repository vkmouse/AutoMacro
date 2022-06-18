#pragma once
#include <chrono>
#include <string>
#include <vector>

namespace AutoMacro {
namespace History {
class History {
 public:
    static bool durationIsInRange(const History& start, const History& last,
        int lowerb, int upperb) {
        using std::chrono::duration_cast;
        using std::chrono::milliseconds;
        auto duration = duration_cast<milliseconds>(last.time() - start.time());
        return lowerb < duration.count() && duration.count() < upperb;
    }

    History(std::string message, std::vector<void*> parameters) :
        message_(message), parameters_(parameters) {
        time_ = std::chrono::high_resolution_clock::now();
    }

    bool equals(std::string message) const {
        return message == message_ && parameters_.size() == 0;
    }

    template <typename T>
    bool equals(std::string message, T parameter) const {
        T* ptr = reinterpret_cast<T*>(parameters_.back());
        return message == message_ && parameter == *ptr;
    }

    template <typename T, typename ...Ts>
    bool equals(std::string message, T parameter, Ts... parameters) const {
        size_t lastIndex = parameters_.size() - 1;
        size_t currentIndex = lastIndex - sizeof...(parameters);
        T* ptr = reinterpret_cast<T*>(parameters_.at(currentIndex));

        if (parameter == *ptr) {
            return equals(message, parameters...);
        } else {
            return false;
        }
    }

    std::chrono::steady_clock::time_point time() const {
        return time_;
    }

    std::string message() const {
        return message_;
    }

    std::vector<void*> parameters() const {
        return parameters_;
    }

 private:
    std::chrono::steady_clock::time_point time_;
    std::string message_;
    std::vector<void*> parameters_;
};
}  // namespace History
}  // namespace AutoMacro
