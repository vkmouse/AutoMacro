#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Factory/CheckItemsExistenceCommandFactory.h"
#include "AutoMacro/Command/Command/Parameter/WhileCommandParameter.h"

namespace AutoMacro {
class ExecuteUntilItemsCommandParameter : public WhileCommandParameter {
 public:
    ExecuteUntilItemsCommandParameter(Kvm kvm,
        std::vector<std::shared_ptr<Detector>> detectors,
        std::vector<int> indices,
        std::vector<float> thresholds,
        std::shared_ptr<Command> executeCommand)
        : existenceParameter(kvm, detectors, indices, thresholds) {
        this->executeCommand = executeCommand;
        requestCommand = Factory::createTCommand(&existenceParameter);
    }

    ExecuteUntilItemsCommandParameter(Kvm kvm,
        std::vector<std::shared_ptr<Detector>> detectors,
        std::vector<int> indices,
        std::vector<float> thresholds)
        : existenceParameter(kvm, detectors, indices, thresholds) {}

    void setIsExpectedToExist(bool value) {
        existenceParameter.isExpectedToExist = value;
        requestCommand = Factory::createTCommand(&existenceParameter);
    }

    void setIsExpectedToAllExist(bool value) {
        existenceParameter.isExpectedToAllExist = value;
        requestCommand = Factory::createTCommand(&existenceParameter);
    }

 private:
    CheckItemsExistenceCommandParameter existenceParameter;
};
}  // namespace AutoMacro
