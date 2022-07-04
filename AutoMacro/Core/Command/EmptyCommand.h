#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Core/Command/Command.h"
#include "AutoMacro/Core/Command/CommandParameter.h"

namespace AutoMacro {
namespace Impl {
class EmptyCommandParameter : public CommandParameter {
 public:
    EmptyCommandParameter() : CommandParameter(Kvm()) {}
};

class EmptyCommand : public Command {
 public:
    EmptyCommand() : Command(&p) {}

    void execute() override {}

 protected:
    virtual void executeCommand() {}

 private:
    EmptyCommandParameter p;
};
}  // namespace Impl
}  // namespace AutoMacro
