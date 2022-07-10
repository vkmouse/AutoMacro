#pragma once
#include <memory>
#include <vector>

#include "AutoMacro/Core/Core.h"
#include "AutoMacro/Command/Command/Factory/DelayCommandFactory.h"
#include "AutoMacro/Command/Command/Factory/EmptyCommandFactory.h"
#include "AutoMacro/Command/Command/Parameter/ExecuteUntilItemsCommandParameter.h"

namespace AutoMacro {
class WaitForItemsCommandParameter : public ExecuteUntilItemsCommandParameter {
 public:
    WaitForItemsCommandParameter(Kvm kvm,
        std::vector<std::shared_ptr<Detector>> detectors,
        std::vector<int> indices,
        std::vector<float> thresholds)
        : ExecuteUntilItemsCommandParameter(kvm, detectors,
                                            indices, thresholds),
          delayParameter(kvm) {
        executeCommand = Factory::createCommand(&delayParameter);
    }

    void setDelayBetweenRepeatitions(int value) {
        delayParameter.ms = value;
        executeCommand = Factory::createCommand(&delayParameter);
    }

 private:
    DelayCommandParameter delayParameter;
};
}  // namespace AutoMacro
