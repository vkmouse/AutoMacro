#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Factory/CheckItemExistenceCommandFactory.h"

namespace AutoMacro {
class ExecuteUntilItemCommandParameter
    : public CheckItemExistenceCommandParameter {
 public:
    ExecuteUntilItemCommandParameter(Kvm kvm,
        std::shared_ptr<Detector> detector, int index, float threshold)
        : CheckItemExistenceCommandParameter(kvm, detector, index, threshold) {}

    ExecuteUntilItemCommandParameter(Kvm kvm,
        std::shared_ptr<Detector> detector, int index, float threshold,
        std::shared_ptr<Command> executeCommand)
        : CheckItemExistenceCommandParameter(kvm, detector, index, threshold),
          executeCommand(executeCommand) {}

    std::shared_ptr<Command> executeCommand = nullptr;
};
}  // namespace AutoMacro
