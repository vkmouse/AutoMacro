#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Core/Command/Command.h"

namespace AutoMacro {
namespace Impl {
class Commands : public TCommand<void> {
 public:
    explicit Commands(std::vector<std::shared_ptr<Command>> commands);

    void execute() final;

 private:
    std::vector<std::shared_ptr<Command>> commands_;
};
}  // namespace Impl
}  // namespace AutoMacro
