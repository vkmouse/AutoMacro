#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Parameter/WhileCommandParameter.h"

namespace AutoMacro {
class ExecuteUntilCommandParameter : public WhileCommandParameter {
 public:
    using WhileCommandParameter::WhileCommandParameter;

    bool useLoopCounter = false;
    int numLoops = 1;
};
}  // namespace AutoMacro
