#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Command/Command/Parameter/ArithmeticOperationCommandParameter.h"

namespace AutoMacro {
namespace Impl {
class ArithmeticOperationCommand : public TCommand<void> {
 public:
    explicit ArithmeticOperationCommand(ArithmeticOperationCommandParameter* p);

    virtual void execute();

 private:
    int* lhs;
    int rhs;
    ArithmeticOperator op;
};
}  // namespace Impl
}  // namespace AutoMacro
