#pragma once
#include "AutoMacro/Core/Core.h"

namespace AutoMacro {
namespace Impl {
class ActualDelay : public Delay {
 public:
    virtual void execute(int ms);
};
}  // namespace Impl
}  // namespace AutoMacro
