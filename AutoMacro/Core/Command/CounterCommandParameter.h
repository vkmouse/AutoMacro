#pragma once
namespace AutoMacro {
class CounterCommandParameter {
 public:
    explicit CounterCommandParameter(int* count) : count(count) {}

    int* count;
};
}  // namespace AutoMacro
