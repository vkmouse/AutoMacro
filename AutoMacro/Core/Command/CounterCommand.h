#pragma once
#include "AutoMacro/Core/Command/Command.h"
#include "AutoMacro/Core/Command/CounterCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class CounterCommand : public TCommand<void> {
 public:
    explicit CounterCommand(CounterCommandParameter* p);

    virtual void execute();

 private:
    int* count_;
};
}  // namespace Impl
}  // namespace AutoMacro
