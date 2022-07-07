#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Cv/Command/CheckExistenceCommandParameter.h"

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
