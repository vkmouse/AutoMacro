#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Factory/CheckItemsExistenceCommandFactory.h"
#include "AutoMacro/Command/Command/Factory/DelayCommandFactory.h"
#include "AutoMacro/Command/Command/Parameter/WhileCommandParameter.h"

namespace AutoMacro {
class WaitForItemsCommandParameter : public WhileCommandParameter {
 public:
    WaitForItemsCommandParameter(Kvm kvm,
        std::vector<std::shared_ptr<Detector>> detectors,
        std::vector<int> indices,
        std::vector<float> thresholds)
        : existenceParameter(kvm, detectors, indices, thresholds),
          delayParameter(kvm) {}

    void setDelayBetweenRepeatitions(int value) {
        delayParameter.ms = value;
        executeCommand = Factory::createCommand(&delayParameter);
    }

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
    DelayCommandParameter delayParameter;
};
}  // namespace AutoMacro
