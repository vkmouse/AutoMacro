#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Command/CheckExistenceCommand.h"
#include "AutoMacro/Command/Command/Parameter/CheckItemExistenceCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class CheckItemExistenceCommand : public CheckExistenceCommand {
 public:
    explicit CheckItemExistenceCommand(CheckItemExistenceCommandParameter* p);

 protected:
    virtual bool executeCommand();

 private:
    std::shared_ptr<Detector> detector_;
    int index_;
    float threshold_;
};
}  // namespace Impl
}  // namespace AutoMacro
