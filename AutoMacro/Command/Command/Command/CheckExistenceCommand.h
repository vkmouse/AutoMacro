#pragma once
#include "AutoMacro/Command/Command/Command/KvmCommand.h"
#include "AutoMacro/Command/Command/Parameter/CheckExistenceCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class CheckExistenceCommand : public KvmCommand<bool> {
 public:
    explicit CheckExistenceCommand(CheckExistenceCommandParameter* p)
        : KvmCommand(p), isExpectedToExist_(p->isExpectedToExist) {}

 protected:
    bool isExpectedToExist() { return isExpectedToExist_; }

 private:
    bool isExpectedToExist_;
};
}  // namespace Impl
}  // namespace AutoMacro
