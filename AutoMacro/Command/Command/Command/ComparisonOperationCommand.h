#pragma once
#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Parameter/ComparisonOperationCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class ComparisonOperationCommand : public TCommand<bool> {
 public:
    explicit ComparisonOperationCommand(ComparisonOperationCommandParameter* p);

    virtual bool execute();

 private:
    const int& lhs;
    int rhs;
    ComparisonOperator op;
};
}  // namespace Impl
}  // namespace AutoMacro
