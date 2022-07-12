#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Factory/CheckItemsExistenceCommandFactory.h"
#include "AutoMacro/Command/Command/Parameter/WhileCommandParameter.h"

namespace AutoMacro {
class ExecuteUntilItemsCommandParameter
    : public CheckItemsExistenceCommandParameter {
 public:
    ExecuteUntilItemsCommandParameter(Kvm kvm,
        std::vector<std::shared_ptr<Detector>> detectors,
        std::vector<int> indices,
        std::vector<float> thresholds)
        : CheckItemsExistenceCommandParameter(
            kvm, detectors, indices, thresholds) {}

    ExecuteUntilItemsCommandParameter(Kvm kvm,
        std::vector<std::shared_ptr<Detector>> detectors,
        std::vector<int> indices,
        std::vector<float> thresholds,
        std::shared_ptr<Command> executeCommand)
        : CheckItemsExistenceCommandParameter(
            kvm, detectors, indices, thresholds),
          executeCommand(executeCommand) {}

    std::shared_ptr<Command> executeCommand = nullptr;
};
}  // namespace AutoMacro
