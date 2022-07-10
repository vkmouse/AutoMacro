#pragma once
#include "AutoMacro/Command/Command/Command/KvmCommand.h"
#include "AutoMacro/Command/Command/Parameter/DelayCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class DelayCommand : public KvmCommand<void> {
 public:
    explicit DelayCommand(DelayCommandParameter* p);

 protected:
    virtual void executeCommand();

 private:
    int ms_;
};
}  // namespace Impl
}  // namespace AutoMacro
