#pragma once
#include "AutoMacro/Core/Command/DelayCommandParameter.h"
#include "AutoMacro/Core/Command/KvmCommand.h"

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
