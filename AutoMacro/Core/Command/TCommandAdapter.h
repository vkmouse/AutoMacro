#pragma once
#include <memory>

#include "AutoMacro/Core/Command/Command.h"

namespace AutoMacro {
namespace Impl {
template<class T>
class TCommandAdapter : public Command {
 public:
    explicit TCommandAdapter(std::shared_ptr<TCommand<T>> command)
        : command_(command) {
    }

    void execute() final {
        command_->execute();
    }

 private:
     std::shared_ptr<TCommand<T>> command_;
};
}  // namespace Impl
}  // namespace AutoMacro
