#pragma once
#include <memory>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Factory/CheckItemExistenceCommandFactory.h"
#include "AutoMacro/Command/Command/Factory/DelayCommandFactory.h"
#include "AutoMacro/Command/Command/Parameter/WhileCommandParameter.h"

namespace AutoMacro {
class ExecuteUntilItemCommandParameter : public WhileCommandParameter {
 public:
    ExecuteUntilItemCommandParameter(Kvm kvm,
        std::shared_ptr<Detector> detector, int index, float threshold,
        std::shared_ptr<Command> executeCommand)
        : existenceParameter(kvm, detector, index, threshold) {
        this->executeCommand = executeCommand;
    }

    ExecuteUntilItemCommandParameter(Kvm kvm,
        std::shared_ptr<Detector> detector, int index, float threshold)
        : existenceParameter(kvm, detector, index, threshold) {}

    void setIsExpectedToExist(bool value) {
        existenceParameter.isExpectedToExist = value;
        requestCommand = Factory::createTCommand(&existenceParameter);
    }

 private:
    CheckItemExistenceCommandParameter existenceParameter;
};
}  // namespace AutoMacro
