#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Command/Command/Parameter/LogicalOperationCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class LogicalOperationCommand : public TCommand<bool> {
 public:
    explicit LogicalOperationCommand(LogicalOperationCommandParameter* p);

    virtual bool execute();

 private:
    std::vector<std::shared_ptr<TCommand<bool>>> commands;
    LogicalOperator op;
};
}  // namespace Impl
}  // namespace AutoMacro
