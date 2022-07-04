#pragma once
#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace CoreTest {
class CounterCommandParameter : public CommandParameter {
 public:
    CounterCommandParameter(Kvm kvm, int* count)
        : CommandParameter(kvm), count(count) {}
    int* count;
};

class CounterCommand : public Command {
 public:
    explicit CounterCommand(CounterCommandParameter* p);

 protected:
    virtual void executeCommand();

 private:
    int* count_;
};
}  // namespace CoreTest
}  // namespace AutoMacro
