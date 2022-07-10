#pragma once
#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Parameter/CounterCommandParameter.h"

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
