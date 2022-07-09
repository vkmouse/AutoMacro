#pragma once
#include "AutoMacro/Core/Kvm/Delay.h"

namespace AutoMacro {
namespace Impl {
class MockDelay : public Delay {
 public:
    virtual void execute(int ms) {}
};
}  // namespace Impl
}  // namespace AutoMacro
