#pragma once
#include "AutoMacro/Core/Command/Command.h"

namespace AutoMacro {
namespace Impl {
template<typename T>
class EmptyCommand : public TCommand<T> {
 public:
    virtual T execute() { return T(); }
};
}  // namespace Impl
}  // namespace AutoMacro
