#pragma once
#include "AutoMacro/Core/Command/Command.h"

namespace AutoMacro {
namespace Impl {
template<typename T>
class EmptyCommand : public TCommand<T> {
 public:
    virtual T execute();
};

template<>
void EmptyCommand<void>::execute() {
}

template<>
bool EmptyCommand<bool>::execute() {
    return false;
}
}  // namespace Impl
}  // namespace AutoMacro
